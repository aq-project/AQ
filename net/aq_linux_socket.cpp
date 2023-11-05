#include "aq_linux_net.h" // 引入AQ网络库
#include "../aq_error.h" // 引入AQ的错误处理头文件
//extern int aq_socket_buffer_size; // 声明外部变量
std::string aq_socket_connect(int __domain,int __type,char *address,int port,char send_message[]){ // 定义名为 aq_socket_connect 的函数，用于建立网络连接并发送消息和返回响应
    int aq_connect_socket = socket(__domain,__type,0); // 创建一个新的套接字
    if(aq_connect_socket < 0){ // 检查套接字是否创建成功
        return "ERROR in socket creation"; // 如果创建失败，返回错误信息
    }
    struct sockaddr_in aq_connect_address; // 定义一个Internet套接字地址结构体
    aq_connect_address.sin_family = __domain; // 设置地址族为用户指定的域
    aq_connect_address.sin_port = htons(port); // 设置端口号，htons函数用于将主机字节序转换为网络字节序
    aq_connect_address.sin_addr.s_addr = inet_addr(address); // 设置IP地址，inet_addr函数用于将点分十进制IP地址转换为网络字节序的整数形式
    if(connect(aq_connect_socket,(struct sockaddr*)&aq_connect_address,sizeof(aq_connect_address)) < 0){ // 尝试连接到服务器，如果连接失败则关闭套接字并返回错误信息
        close(aq_connect_socket);
        return "ERROR in connection";
    }
    write(aq_connect_socket, send_message, strlen(send_message)); // 向服务器发送消息，使用strlen函数获取消息长度

    char buffer[aq_socket_buffer_size]; // 定义一个缓冲区，用于存储服务器的响应消息
    memset(buffer, 0, sizeof(buffer)); // 使用memset函数将缓冲区初始化为0

    std::string response; // 定义一个字符串，用于存储服务器的响应消息

    ssize_t n; // 定义一个变量n，用于存储read函数的返回值

    while((n = read(aq_connect_socket, buffer, sizeof(buffer)-1)) > 0){ // 循环读取服务器的响应消息，直到没有数据可读
        buffer[n] = '\0'; // 在缓冲区末尾添加一个null字符，以确保字符串的正确结束
        response += buffer; // 将缓冲区中的数据添加到响应字符串中
        memset(buffer, 0, sizeof(buffer)); // 清空缓冲区，以便下一次读取数据
    }
    if(n < 0){ // 如果read函数返回负值，说明读取数据时出错，关闭套接字并返回错误信息
        close(aq_connect_socket);
        return "ERROR in read";
    }
    close(aq_connect_socket); // 关闭套接字

    return response; // 返回服务器的响应消息
}

/*int main(){ 
    std::cout << aq_socket_connect(AF_INET,SOCK_STREAM,"1.1.1.1",80,"GET / HTTP/1.1\r\nHost: 1.1.1.1\r\nConnection: close\r\n\r\n"); 
// 在主函数中调用aq_socket_connect函数，并打印其返回值。这里我们尝试连接到IP地址为"1.1.1.1"的服务器的80端口，并发送一个HTTP GET请求。
}*/
