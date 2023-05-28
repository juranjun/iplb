#include <iostream>
#include "conf.h"
#include "util.h"
#include <unistd.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    conf *gconf = new conf();
    gconf->addNode(new next(123));

    ipv4toInt("12.12.12.12");
    ipv4toString(202116108);
//    while(true) {
//        usleep(1000);
//    }
    return 0;
}
