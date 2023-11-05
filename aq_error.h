//AQ错误处理头文件
#ifndef aq_error // 检查是否已经定义了名为 aq_error 的宏
    #define aq_error // 定义名为 aq_error 的宏
    #include <string> // 引用 string 头文件
    extern void aq_error_report(std::string error_message); // 定义名为 aq_error_report 的函数，用于处理错误信息
#endif // 头文件的结尾