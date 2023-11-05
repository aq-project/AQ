//AQ网络库头文件
#ifndef aq_net // 检查是否已经定义了名为 aq_net 的宏
    #define aq_net // 定义名为 aq_net 的宏
    #ifdef __unix__ // 判断系统类型
        #include "aq_linux_net.h" // 引入 AQ-Linux 网络库
    #endif // 结束判断
#endif // 头文件的结尾