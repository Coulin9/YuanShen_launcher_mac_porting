# 这是什么？

一个基于 [WineSkin](https://github.com/Gcenx/WineskinServer)的PC原神移植版本。

# 优势

对于小白用户，免去了wine环境（Crossover/Whisky）的配置，脚本一键安装。

# 系统要求

+ **Apple Silicon Mac**  
+ **macOSVersion >= 14.4**

# 如何安装？

+ 打开终端，输入代码`curl -sL -o ~/launch_YuanShen.sh https://gitee.com/Coulin9/YuanShen_launcher_mac_porting/raw/main/launch_YuanShen.sh && chmod +x ~/launch_YuanShen.sh && ~/launch_YuanShen.sh`并回车
+ 如果提示下载Xcode CommandLine Tools，请下载安装完成后重新执行上述代码

# ChangeLogs
+ V0.1.1
    + 更新启动器版本为20240313191154
    + 增加了对移动硬盘的支持，现在你应该可以在D盘下找到你的移动硬盘
+ V0.1.2
    + 更新winskin engine版本为CX23.7.1-2
+ V0.1.3
    + 更新winskin engine为wineStaging9.3