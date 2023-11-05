//AQ的主程序头文件
#ifndef aq_main // 检查是否已经定义了名为 aq_net 的宏
    #define aq_main // 定义名为 aq_error 的宏
    #include <string> // 引入 string 头文件
    extern int aq_init();
    extern int aq_net_init();
    extern std::string bns_address; // 定义全局的bns地址变量
    extern std::string bns_querier(std::string query_address); // 声明bns查询器函数
#endif
