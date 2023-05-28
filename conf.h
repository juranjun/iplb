//
// Created by dingding on 2023/5/27.
//

#ifndef IPLB_CONF_H
#define IPLB_CONF_H


#include "next.h"
#include <map>

class conf {
public:
    conf();
    int addNode(next* n);

private:
    ~conf();
    int max_index;
    int cur_index;
    std::map<int, next*> m_next;
};


#endif //IPLB_CONF_H
