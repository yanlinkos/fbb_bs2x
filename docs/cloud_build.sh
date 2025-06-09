#!/bin/bash
BUILD_SOURCE=$1
CODEHUB_URL=$2
CODEHUB_BRANCH=$3

if [ -z "${DOCS_DIR}" ]; then
    DOCS_DIR="docs"
fi


function install_py_libs() {
    # 安装构建依赖
    # requirements_txt：流水线自定义参数
    txt_file=requirements.txt
    if [ ! -f "${txt_file}" ]; then
        echo "missing ${txt_file}"
        exit 1
    fi
    pip install -r $txt_file -i ${PIP_URL} --trusted-host ${PIP_HOST}
    sleep 1
    if [ -z "${BUILD_SOURCE}" ]; then
        # python是模板容器自定义安装的，根据创建流水线选择的模板确定
        ls -alh /opt/tools/python/3.8.18/Python-3.8.18/bin | grep sphinx
        # 安装sphinx无法执行build命令，需要进行设置PATH变量
        export PATH=/opt/tools/python/3.8.18/Python-3.8.18/bin:$PATH
    fi
}


function check_success() {
    if [ $? -eq 0 ]; then
        echo "$1 run success!"
    else
        echo "$1 run failed!"
        exit 1
    fi
}


function sphinx_build_and_obs_upload() {
    # sphinx构建+obs上传
    src_dir=$1  # 文档路径
    out_dir=$2  # 构建输出路径，同事也是OBS的objectKey
    if [ -f "${out_dir}" ]; then
        rm -rf ${out_dir}
    fi
    echo "build doc source: ${src_dir}, build output dir(OBS objectKey): ${out_dir}"
    sphinx-build -b html ${src_dir} ${out_dir}
    check_success "sphinx-build html"

    ls -alh
    # 默认上传
    if [ "${OBS_UPLOAD}" != "false" ]; then
        echo "start to upload file to OBS..."
        python obs_upload.py -ak ${OBS_AK} -sk ${OBS_SK} -bucket ${OBS_BUCKET} -server ${OBS_SERVER} -src ${out_dir} -key ${out_dir}
        check_success "OBS upload"
    fi
}


function docs_build_start() {
    repo_path=$1
    repo_branch=$2
    chip=$3

    key_prefix="${OBS_ROOT_KEY}/${repo_path}"
    if [ -n "${chip}" ]; then
        # 如 bs2x/docs/en
        dir_path_prefix="${chip}/${DOCS_DIR}"
        key_suffix="${repo_branch}/${chip}"
    else
        dir_path_prefix=$DOCS_DIR
        key_suffix=$repo_branch
    fi

    has_language="false"
    en="en"
    if [ -d "${en}" ]; then
        echo "start to build docs, language: ${en}"
        has_language="true"
        obs_object_key="${key_prefix}/${en}/${key_suffix}"
        sphinx_build_and_obs_upload ${en} $obs_object_key
    else
        echo "path not exist: ${en}, ignore to build en docs"
    fi

    zh_CN='zh-CN'
    if [ -d "${zh_CN}" ]; then
        echo "start to build docs, language: ${zh_CN}"
        has_language="true"
        obs_object_key="${key_prefix}/${zh_CN}/${key_suffix}"
        sphinx_build_and_obs_upload ${zh_CN} $obs_object_key
    else
        echo "path not exist: ${zh_CN}, ignore to build zh-CN docs"
    fi

    if [ "${has_language}" == "false" ]; then
        echo "start to build docs, language docs dir not exist"
        obs_object_key="${key_prefix}/${key_suffix}"
        sphinx_build_and_obs_upload . $obs_object_key
    fi
}


function to_html_and_upload() {
    install_py_libs
    repo_path=$1
    repo_branch=$2

    # 文档路径，默认都是仓目录下面的docs文件夹，还需要适配是否存在中英文文件夹
    if [ -z "${MULTI_CHIP}" ]; then
        # 单仓芯片
        docs_build_start $repo_path $repo_branch
    else
        # 多仓芯片
        for chip in ${MULTI_CHIP}; do
            docs_build_start $repo_path $repo_branch $chip
        done
    fi
}

# gitee构建
function gitee_build() {
    echo "build env: gitee"
    # WEBHOOK_PAYLOAD：流水线系统参数，gitee的webhook触发回调传参
    gitee_action=$(echo $WEBHOOK_PAYLOAD | jq '.action')
    if [ -z "${gitee_action}" ]; then
        echo "WEBHOOK_PAYLOAD data not found!"
        exit 1
    else
        # 触发的分支/tag名称，TARGET_BRANCH 流水线系统变量
        export REPO_BRANCH=$TARGET_BRANCH

        # jq解析webhook的json数据获取值
        is_created=$(echo $WEBHOOK_PAYLOAD | jq -r '.created')
        is_deleted=$(echo $WEBHOOK_PAYLOAD | jq -r '.deleted')
        hook_name=$(echo $WEBHOOK_PAYLOAD | jq -r '.hook_name')
        echo "构建webhook类型：${hook_name}, created: ${is_created}, deleted: ${is_deleted}"

        if [ "${hook_name}" == "merge_request_hooks" ]; then
            # PR合入
            # 获取target_branch和state即可
            state=$(echo $WEBHOOK_PAYLOAD | jq -r '.state')
            # target_branch=$(echo $WEBHOOK_PAYLOAD | jq -r '.target_branch')
            if [ "${state}" != "merged" ]; then
                # 可能是pr新建、更新等
                echo "PR未合入，忽略本次构建"
                exit 0
            fi
        elif [ "${hook_name}" == "tag_push_hooks" ]; then
            # tag新建或者删除
            if [ "${is_created}" == "true" ]; then
                echo "tag新增操作"
                # tag新增分支需要覆盖为TAG 流水线系统变量
                export REPO_BRANCH=$TAG
            else
                echo "非tag新增操作，忽略本次构建"
                exit 0
            fi
        elif [ "${hook_name}" == "push_hooks" ]; then
            # 代码合入、分支增删
            if [ "${is_created}" == "false" -a "${is_deleted}" == "true" ]; then
                echo "分支删除操作，忽略本次构建"
                exit 0
            elif [ "${is_created}" == "true" ]; then
                echo "新建分支操作"
            else
                echo "代码合入操作"
            fi
        elif [ "${hook_name}" == "note_hooks" ]; then
            echo "comment building"
        else
            echo "未适配的webhook数据，忽略本次构建"
            exit 1
        fi

        export REPO_NAMESPACE=$(echo $WEBHOOK_PAYLOAD | jq -r '.repository.namespace')

        # gitee路径使用小写
        export REPO_PATH=$(echo $WEBHOOK_PAYLOAD | jq -r '.repository.path')

        private_repo=$(echo $WEBHOOK_PAYLOAD | jq -r '.repository.private')
        echo "当前构建仓库属性private：${private_repo}"

        echo "组织：${REPO_NAMESPACE}，仓名：${REPO_PATH}，分支/tag ${REPO_BRANCH}"
        to_html_and_upload $REPO_PATH $REPO_BRANCH
    fi
}


function codehub_build() {
    echo "build env: codehub"
    export REPO_NAMESPACE=$CODEHUB_NAMESPACE
    export REPO_PATH=$CODEHUB_PATH
    export REPO_HOST=$CODEHUB_HOST
    export REPO_BRANCH=$CODEHUB_BRANCH
    to_html_and_upload $REPO_PATH $CODEHUB_BRANCH
}


function local_build() {
    echo "build env: local"
}


function main() {
    if [ -z "${BUILD_SOURCE}" ]; then
        echo "generate doc index.rst"
        python make_index.py
        echo "rst file generate done."
        gitee_build
    elif [ "${BUILD_SOURCE}" == "jenkins" ]; then
        codehub_build
    else
        local_build
    fi
}

main
