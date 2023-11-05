#!/bin/bash
# aq_install.sh
if [ "$1" == "" ] || [ "$1" == "help" ] || [ "$1" == "-h" ] || [ "$1" == "--h" ]; then # 判断是否输出帮助
    echo "Usage: ./aq_install.sh install" # 输出帮助内容
    exit 1 # 退出程序
fi # 结束判断
if [ "$1" == "install" ] || [ "$1" == "-i" ] || [ "$1" == "--i" ]; then # 判断是否进行安装
    if ! command -v g++ &> /dev/null; then # 判断 g++ 是否存在
        echo "g++ could not be found, please install it." # 输出错误信息
        exit 1 # 退出程序
    fi # 结束判断
    g++ *.cpp net/*.cpp -o aq_app # 执行 g++ 编译
    if [ $? -eq 0 ]; then # 判断编译是否成功
        echo "Compilation successful." # 输出成功信息
    else #判断生成失败
        echo "Compilation failed." # 输出错误信息
        exit 1 # 退出程序
    fi # 结束判断
fi # 结束判断