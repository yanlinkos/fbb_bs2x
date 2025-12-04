#===============================================================================
# @brief    cmake make file
# Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
#===============================================================================
function(slp_fw_path input_target_name output_slp_fw_path)
    if(${input_target_name} STREQUAL "bs21a_n1200_slp_car_rcu")
        set(FW_PATH "wb_output/car_rcu/file_array")
    elseif(${input_target_name} STREQUAL "bs21a_n1200_slp_car_dongle")
        set(FW_PATH "wb_output/car_dongle/file_array")
    elseif(${input_target_name} STREQUAL "bs21a_n1200_slp_car_radar_only")
        set(FW_PATH "wb_output/car_dongle/file_array")
    elseif(${input_target_name} STREQUAL "bs21a_n1200_slp_tv_rcu")
        set(FW_PATH "wb_output/tv_rcu/file_array")
    elseif(${input_target_name} STREQUAL "bs21a_n1200_slp_tv_dongle")
        set(FW_PATH "wb_output/tv_dongle/file_array")
    elseif(${input_target_name} STREQUAL "bs21e_1100e_slp_car_rcu")
        set(FW_PATH "wb_output/car_rcu/file_array")
    elseif(${input_target_name} STREQUAL "bs21e_1100e_slp_car_dongle")
        set(FW_PATH "wb_output/car_dongle/file_array")
    elseif(${input_target_name} STREQUAL "bs21e_1100e_slp_tv_rcu")
        set(FW_PATH "wb_output/tv_rcu/file_array")
    elseif(${input_target_name} STREQUAL "bs21e_1100e_slp_tv_dongle")
        set(FW_PATH "wb_output/tv_dongle/file_array")
    elseif(${input_target_name} STREQUAL "bs21e_1100e_slp_tv_radar_only")
        set(FW_PATH "wb_output/tv_dongle/file_array")
    else()
        set(FW_PATH "firmware/file_array")
    endif()
    set(${output_slp_fw_path} ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../interim_binary/${CHIP}/bin/slp/${FW_PATH} PARENT_SCOPE)
endfunction()

set(
    tiot_product_src_list
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/w33_board_port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/tiot_board_uart_port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/tiot_board_pin_port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/tiot_board_misc_port.c
)

set(
    tiot_product_header_list
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../common"
)

if(DEFINED CONFIG_FILE_BY_ARRAY)
set(FW_FILE_DES_ARRAY ${CMAKE_CURRENT_SOURCE_DIR}/firmware)
set(FW_FILE_ARRAY ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../interim_binary/${CHIP}/bin/slp/firmware/file_array)
# 根据target名字输出slp固件加载的路径
slp_fw_path("${BUILD_TARGET_NAME}" fw_path)
message(STATUS "Firmware fw_path: ${fw_path}")  # 打印fw_path的值
message(STATUS "Firmware FW_FILE_ARRAY: ${FW_FILE_ARRAY}")  # 打印FW_FILE_ARRAY的值
if(EXISTS ${fw_path})
    file(REMOVE_RECURSE ${FW_FILE_DES_ARRAY}) # 确保文件copy成功
    file(COPY ${fw_path}/ DESTINATION ${FW_FILE_DES_ARRAY})
else()
    message(WARNING "Firmware directory does not exist!")
endif()
list(
    APPEND tiot_product_src_list
    ${CMAKE_CURRENT_SOURCE_DIR}/firmware/w33_fw_file_array.c
)

list(
    APPEND tiot_product_header_list
    "${CMAKE_CURRENT_SOURCE_DIR}/firmware"
)
endif()

set(TIOT_HEADER_LIST "${TIOT_HEADER_LIST}" "${tiot_product_header_list}" CACHE INTERNAL "tiot header list" FORCE)
set(TIOT_SRC_LIST "${TIOT_SRC_LIST}" "${tiot_product_src_list}" CACHE INTERNAL "tiot src list" FORCE)