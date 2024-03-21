#!/bin/bash  

cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P

sudo spctl --master-disable

read -p "是否已在 设置->隐私与安全性->安全性->允许从以下位置下载的应用程序 中开启任何来源? (y/N) " CHOICE  
CHOICE=$(echo "$CHOICE" | tr '[:upper:]' '[:lower:]') 
if [ "$CHOICE" != "y" ]; then  
    echo "错误: 请开启允许任何来源."  
    exit 1  
fi
 
APP_NAME="原神.app"  
APP_PATH="./$APP_NAME"    
macOS_version=$(sw_vers -productVersion)   
machine_type=$(uname -m)

if [ $machine_type != "arm64" ]; then
    echo "错误: 目前仅支持Apple Silicon Mac"
    exit 1
fi

if [ macOS_version < "14.4" ]; then
    echo "错误: 只支持macOS14.4及以上系统版本"
    exit 1
fi
  
if [ ! -d "$APP_PATH" ]; then  
    echo "错误: 在当前目录下未找到'$APP_NAME'。"  
    exit 1  
fi  
  
# 移除com.apple.quarantine校验  
sudo xattr -r -d com.apple.quarantine "$APP_PATH"   
  
# 将应用移动到Applications文件夹  
DESTINATION="/Applications/$APP_NAME"  
  
# 如果目标路径已存在，则询问用户是否覆盖  
if [ -e "$DESTINATION" ]; then  
    read -p "警告: '$DESTINATION' 已存在. 是否覆盖? (y/N) " CHOICE  
    CHOICE=$(echo "$CHOICE" | tr '[:upper:]' '[:lower:]')  
    if [ "$CHOICE" != "y" ]; then  
        echo "安装已取消."  
        exit 0  
    fi 
    sudo rm -rf "$DESTINATION" 
fi  

# 移动应用  
sudo mv "$APP_PATH" "$DESTINATION"  
  
if [ $? -ne 0 ]; then  
    echo "安装失败！"  
    exit 1  
fi  
  
echo "安装成功！"