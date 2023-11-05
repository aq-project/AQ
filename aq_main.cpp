#include "aq_main.h"
#include "aq_error.h"
#include "net/aq_linux_net.h"
int main(){
    aq_init();
    //aq_error_report("1");
    std::cout << aq_dns_query("com");  
    return 0;
}
