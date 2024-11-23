# 这是什么？

一个基于 [WineSkin](https://github.com/Gcenx/WineskinServer)的PC原神/绝区零移植版本。

# 优势

对于小白用户，免去了wine环境（Crossover/Whisky）的配置，脚本一键安装。

# 系统要求

+ **Apple Silicon Mac**  
+ **macOSVersion >= 14.4**

# 首次安装游戏请执行：

+ **步骤1**:安装homebrew，如果你已经安装好了homebrew，可以跳过这一步
  + 如果你在国内，请依次在终端执行：
    + `/bin/bash -c "$(curl -fsSL https://gitee.com/ineo6/homebrew-install/raw/master/install.sh)"` 如果卡住，请按`Control + C`中断脚本执行，再重新执行前面的命令，看到 `==> Installation successful!` 说明安装成功
    + `git -C "$(brew --repo)" remote set-url origin https://mirrors.ustc.edu.cn/brew.git`
    + 重启终端
    + `brew update`
  + 如果你在国外，请依次在终端执行：
    + `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
    + 重启终端
    + `brew update`
+ **步骤2**:安装kotlin，如果你已经安装了kotlin，可以跳过这一步
  + 在终端执行命令`brew install kotlin`，等待安装完成
+ **步骤3**:克隆项目
  + 如果你在国内，请在终端执行：`git clone https://gitee.com/Coulin9/YuanShen_launcher_mac_porting.git`
  + 如果你在国外，请在终端执行：`git clone https://github.com/Coulin9/YuanShen_launcher_mac_porting.git`
  + Tips:**如果提示下载Xcode CommandLine Tools，请下载安装完成后重新执行步骤3**
+ **步骤4**:定位到项目目录
  + 在终端执行命令`cd YuanShen_launcher_mac_porting`
+ **步骤5**:运行安装脚本
  + 在终端执行命令`kotlinc -script install_or_update_game_package.main.kts`
+ **步骤6**:使用安装脚本安装游戏
  + 选择要安装的游戏后脚本将自动执行，期间会下载并解压游戏数据包，可能需要30min以上，如果最后提示`解压完成`表明安装成功。
+ **步骤7**:在启动台找到游戏并启动

# 后续如何更新游戏？

+ **步骤1**:定位到项目目录
  + 在终端执行命令`cd YuanShen_launcher_mac_porting`
+ **步骤2**:更新安装脚本
  + 在终端执行命令`git pull origin main`
+ **步骤3**:运行安装脚本
  + 在终端执行命令`kotlinc -script install_or_update_game_package.main.kts`

![ScreenShot.png](ScreenShot.png)

# ChangeLogs
+ V0.1.1
    + 更新启动器版本为20240313191154
    + 增加了对移动硬盘的支持，现在你应该可以在D盘下找到你的移动硬盘
+ V0.1.2
    + 更新winskin engine版本为CX23.7.1-2
+ V0.1.3
    + 更新winskin engine为wineStaging9.3
+ V1.0.0
  + 新增绝区零安装支持
  + 去掉了官方启动器，改为脚本安装游戏数据
  + GPTK更新为2.0b11
+ V1.0.1
  + 修复了原神5.1版本“机器环境异常”被踢下线的问题
  + 更新winskin engine为WS12WineCX64Bit23.7.1-4_D3DMetal-v2.0b2
+ V1.1.0
  + 图形转译方案更改为DXMT，修复图形问题，提升性能。
  + 优化了安装步骤指引
+ V1.1.1
  + 继续优化安装指引