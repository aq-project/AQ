/*#include <openssl/bio.h> // OpenSSL BIO库，用于I/O操作
#include <openssl/ssl.h> // OpenSSL SSL库，用于SSL/TLS协议
#include <openssl/err.h> // OpenSSL错误处理库
#include <iostream>

int main() {
    // 初始化OpenSSL库
    SSL_library_init(); // 初始化SSL库
    SSL_load_error_strings(); // 加载SSL错误信息

    // 创建SSL上下文
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method()); // 创建新的SSL上下文，使用SSLv23客户端方法

    if (ctx == NULL) {
        ERR_print_errors_fp(stderr); // 如果创建失败，打印错误信息
        return 1;
    }

    // 创建新的BIO对象，连接到HTTPS服务器
    BIO *web = BIO_new_ssl_connect(ctx); // 创建新的BIO对象

    if (web == NULL) {
        ERR_print_errors_fp(stderr); // 如果创建失败，打印错误信息
        return 1;
    }

    // 设置连接的主机和端口
    BIO_set_conn_hostname(web, "www.github.com:https"); // 设置连接的主机和端口

    // 建立连接
    if (BIO_do_connect(web) <= 0) {
        ERR_print_errors_fp(stderr); // 如果连接失败，打印错误信息
        return 1;
    }

    // 发送HTTP请求
    char buf[1024];
    //snprintf(buf, sizeof(buf), "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    BIO_puts(web, buf); // 发送HTTP请求

    // 读取HTTP响应
    while (1) {
        memset(buf, 0, sizeof(buf));
        int len = BIO_read(web, buf, sizeof(buf) - 1);
        
        if (len <= 0) {
            
            break;
        } // 如果读取完毕或出错，跳出循环
        printf("%s", buf); // 打印HTTP响应内容
    }

    // 清理资源
    BIO_free_all(web); // 释放BIO对象
    SSL_CTX_free(ctx); // 释放SSL上下文

    return 0;
}
*/