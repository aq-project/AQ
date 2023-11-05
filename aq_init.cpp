#include "aq_main.h"
#include "aq_error.h"
#include "net/aq_linux_net.h"
int aq_socket_buffer_size;
int aq_init(){
    aq_net_init();
    return 0;
}
int aq_net_init(){
    aq_socket_buffer_size = 1024;
    return 0;
}
