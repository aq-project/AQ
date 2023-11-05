#include "aq_linux_net.h" // 引入AQ网络库的头文件
#include "../aq_error.h" // 引入AQ的错误处理头文件
std::string source_name = "aq_linux_dns"; // 定义源文件名称
sockaddr *aq_dns_query(const char *domain) { // 定义一个名为 aq_dns_query 函数，用于进行DNS查询
    std::string function_name = "aq_dns_query"; // 定义函数名称
    struct addrinfo ip_storage, *ip_address; // 定义地址信息结构体ip_storage和指向地址信息的指针ip_address
    int status; // 定义一个变量，用于存储getaddrinfo函数的返回值
    memset(&ip_storage, 0, sizeof ip_storage); // 将ip_storage结构体的所有字节设置为0
    ip_storage.ai_family = AF_UNSPEC; // 设置地址族为AF_UNSPEC，表示可以返回任何类型的地址（IPv4或IPv6）
    if ((status = getaddrinfo(domain, NULL, &ip_storage, &ip_address)) != 0) { // 调用getaddrinfo函数，进行DNS查询,并判断是否查询成功        aq_error_report();
        std::string getaddrinfo_error = gai_strerror(status); // 如果查询失败，获取getaddrinfo的错误信息
        std::string error_message = source_name + ":" + function_name + ":" + getaddrinfo_error; // 合成全部错误信息
        aq_error_report(error_message);
        return nullptr; // 返回空指针
    }
    sockaddr *return_ip = ip_address->ai_addr; // 从查询结果中获取第一个地址
    freeaddrinfo(ip_address); // 释放由getaddrinfo分配的内存
    return return_ip; // 返回地址结构体指针
}
