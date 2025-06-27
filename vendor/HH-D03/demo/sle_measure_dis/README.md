# 测距

- 步骤一：修改drivers\chips\bs2x\main_init\app_os_init.c中\#define TASK_COMMON_APP_DELAY_MS       20000修改为\#define TASK_COMMON_APP_DELAY_MS       7000

  ```
  #define TASK_COMMON_APP_DELAY_MS       7000
  ```

- 步骤二：将vendor\HH-D03\demo\sle_measure_dis文件夹复制到application\samples\products，选择相同文件覆盖即可

- 步骤三：编译server端，勾选下图几个地方，然后烧录到server端开发板，注意硬件server端需要带一个屏幕

  ![image-20250611114154872](../../doc/media/sle_measure_dis/image-20250611114154872.png)

- 步骤四：编译client端，勾选下图几个地方，然后烧录到client端开发板，注意client端开发板不需要屏幕

  ![image-20250611114347214](../../doc/media/sle_measure_dis/image-20250611114347214.png)
  
- 详细参考<a href="zh-CN/debug/SDK Sample使用指南/BS2XV100 SDK Sample使用指南.md">BS2XV100 SDK Sample使用指南</a>
  
-  效果展示：server端需要带屏幕，展示数据，client端不需要屏幕。

  ![image-20250626092846431](../../doc/media/sle_measure_dis/image-20250626092846431.png)
