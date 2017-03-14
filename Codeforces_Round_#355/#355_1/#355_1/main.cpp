//
//  main.cpp
//  #355_1
//
//  Created by zhoujl on 16/6/2.
//  Copyright (c) 2016年 zhoujl. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
const long long module = 1e9+7;
map<int, int> p;
int main() {
    p['0'] = 64 + 6*32 + 15*16 + 20*8 + 15*4 + 6*3 + 1;
    p['1'] = 32 + 5*16 + 10*8 + 10*4 + 5 * 2 + 1;
    p['2'] = p['1'];
    p['3'] = 16 + 4*8 + 6*4 + 2*4 + 1;
    p['4'] = p['1'];
    p['8'] = p['1'];
    p['G'] = p['1'];
    p['W'] = p['1'];
    p['5'] = p['3'];
    p['9'] = p['3'];
    p['H'] = p['3'];
    p['X'] = p['3'];
    p['6'] = p['3'];
    p['7'] = 8 + 12 + 6 + 1;
    p['A'] = p['3'];
    p['B'] = p['7'];
    p['C'] = p['3'];
    p['D'] = p['7'];
    p['E'] = p['7'];
    p['F'] = 4+4+1;
    p['I'] = p['3'];
    p['J'] = p['7'];
    p['K'] = p['3'];
    p['L'] = p['7'];
    p['M'] = p['7'];
    p['N'] = p['F'];
    p['O'] = p['3'];
    p['P'] = p['7'];
    p['Q'] = p['7'];
    p['R'] = p['F'];
    p['S'] = p['7'];
    p['T'] = p['F'];
    p['U'] = p['F'];
    p['V'] = 3;
    p['Y'] = p['3'];
    p['Z'] = p['7'];
    p['a'] = p['3'];
    p['b'] = p['7'];
    p['c'] = p['7'];
    p['d'] = p['F'];
    p['e'] = p['3'];
    p['f'] = p['7'];
    p['g'] = p['7'];
    p['h'] = p['F'];
    p['i'] = p['7'];
    p['j'] = p['F'];
    p['k'] = p['F'];
    p['l'] = p['V'];
    p['m'] = p['3'];
    p['n'] = p['7'];
    p['o'] = p['7'];
    p['p'] = p['F'];
    p['q'] = p['7'];
    p['r'] = p['F'];
    p['s'] = p['F'];
    p['t'] = p['V'];
    p['u'] = p['7'];
    p['v'] = p['F'];
    p['w'] = p['F'];
    p['x'] = p['V'];
    p['y'] = p['F'];
    p['z'] = p['V'];
    p['-'] = p['V'];
    p['_'] = 1;
    string s;
    cin>>s;
    long long sum = 1;
    for (int i = 0; i < s.length(); i++) {
        sum = (sum*1LL*p[s[i]])%module;
    }
    printf("%lld\n", sum);
    return 0;
}
