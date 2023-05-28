//
// Created by dingding on 2023/5/27.
//

#include "util.h"
#include <iostream>
#include <stdlib.h>

std::string ipv4toString(int ip) {
    int a = ip > 4;
    return "";
}

int exchange_char_int(char c) {
    int b = 0;
    switch (c)
    {
        case '0':b = 0; break;
        case '1':b = 1; break;
        case '2':b = 2; break;
        case '3':b = 3; break;
        case '4':b = 4; break;
        case '5':b = 5; break;
        case '6':b = 6; break;
        case '7':b = 7; break;
        case '8':b = 8; break;
        case '9':b = 9; break;
        case 'A':b = 10; break;
        case 'B':b = 11; break;
        case 'C':b = 12; break;
        case 'D':b = 13; break;
        case 'E':b = 14; break;
        case 'F':b = 15; break;
        default:break;
    }
    return b;
}

char exchange_int_char(int a) {
    char b;
    switch (a)
    {
        case 0:b = '0'; break;
        case 1:b = '1'; break;
        case 2:b = '2'; break;
        case 3:b = '3'; break;
        case 4:b = '4'; break;
        case 5:b = '5'; break;
        case 6:b = '6'; break;
        case 7:b = '7'; break;
        case 8:b = '8'; break;
        case 9:b = '9'; break;
        case 10:b = 'A'; break;
        case 11:b = 'B'; break;
        case 12:b = 'C'; break;
        case 13:b = 'D'; break;
        case 14:b = 'E'; break;
        case 15:b = 'F'; break;
        default:break;
    }
    return b;
}

void inttohex(unsigned int in, char* out) {
    int m = 0;
    int i = 0;
    if (in > 15) {
        while (in >= 16) {
            m = in % 16;
            in = in / 16;
            out[i] = exchange_int_char(m);
            i++;
        }
        out[i] = exchange_int_char(in);
    }
    else {
        out[i] = exchange_int_char(in);
    }
}
// 11 + 11*16^2 + 11*16^4 + 11*16^6
int muti(int time) {
    if (time == 0)
        return 1;
    int out = 1;
    for (int i = 0; i < time; i++) {
        out = 16 * out;
    }
    return out;
}

unsigned int hextoint(char* in, int length) {
    unsigned int out = 0;
    for (int i = length-1; i >= 0; i--) {
        out += exchange_char_int(in[i])*muti(i);
    }
//    std::cout << out << std::endl;
    return out;
}

int ipv4toInt(std::string ip) {
    int rst[4] = {'0'};
    int lastpos = 0;
    int j = 3;
    int i = ip.find('.');
    ip += '.';
    while (i != -1) {
        if (j < 0)
            break;
        rst[j--] = stoi(ip.substr(lastpos, i-lastpos));
        lastpos = i+1;
        i = ip.find('.', lastpos);
    }
    j = 3;
    i = 0;
    char allhexrst[8] = {'0'};
    while(j>=0) {
        char hexrst[2] = {'0'};
        memset(hexrst, '0', 2);
        inttohex(rst[j--], hexrst);
        memcpy(&allhexrst[i], hexrst, 2);
        i += 2;
//        std::cout << hexrst[0] << hexrst[1] << std::endl;
//        std::cout << rst[j] << std::endl;
    }
    for (int k = 8; k > 0; k--) {
        std::cout << allhexrst[k-1];
    };
    std::cout << std::endl;
    std::cout << hextoint(allhexrst, 8) << std::endl;
    return hextoint(allhexrst, 8);
}

std::string ipv4toString(unsigned int ip) {
    char hex[8] = {};
    memset(hex, '0', 8);
    inttohex(ip, hex);
    std::string strhex[4] = {};
    std::string str{hex};
    for (int i = 0; i < 4; i++) {
        strhex[i] = str.substr(i*2, 2);
        int j = hextoint((char*)strhex[i].c_str(), 2);
//        std::cout << strhex[i] << std::endl;
        strhex[i] = std::to_string(j);
//        std::cout << strhex[i] << std::endl;
    }
    for (int i = 8; i > 0; i--) {
        std::cout << hex[i-1];
    }
    std::cout << std::endl;
    std::string strout = "";
    for (int i = 0; i < 4; i++) {
        strout += strhex[i] + ".";
    }
    std::cout << strout.substr(0, strout.length()-1) << std::endl;
    return strout.substr(0, strout.length()-1);
}