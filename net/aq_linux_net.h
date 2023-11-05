//AQ-Linux网络库头文件
#ifndef aq_linux_net // 检查是否已经定义了名为 aq_linux_net 的宏
    #define aq_linux_net // 定义名为 aq_linux_net 的宏
    #include <iostream> // 引入C++标准库中的输入/输出流库
    #include <netdb.h> // 引入用于网络数据库操作的头文件，包含了getaddrinfo等函数的声明
    #include <string.h> // 引入字符串操作的头文件，包含了memset等函数的声明
    #include <sys/types.h> // 包含系统类型定义
    #include <sys/socket.h> // 包含套接字函数库
    #include <netinet/in.h> // 包含Internet地址族
    #include <unistd.h> // 包含Unix系统调用
    #include <arpa/inet.h> // 包含inet函数
    extern std::string aq_socket_connect(int __domain,int __type,char *address,int port,char send_message[]); // 定义名为 aq_socket_connect 的函数，用于建立网络连接并发送消息和返回响应
    extern sockaddr *aq_dns_query(const char *domain); // 定义一个函数，用来执行DNS查询
    extern int aq_socket_buffer_size; // 定义缓冲区大小为1024
#endif // 头文件的结尾