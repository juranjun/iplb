//
// Created by dingding on 2023/5/27.
//

#include "conf.h"

conf::conf() {
    max_index = 0;
}

int conf::addNode(next* n) {
    m_next[cur_index++] = n;
    max_index++;
    return 0;
}
