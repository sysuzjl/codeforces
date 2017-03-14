//
//  main.cpp
//  #380_1
//
//  Created by zhoujl on 16/11/20.
//  Copyright (c) 2016年 zhoujl. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        
        if (i < n-2 && s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
            i+=2;
            while (i < n-2 &&  s[i+1] == 'g' && s[i+2] == 'o') {
                i+=2;
            }
            printf("***");
            
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
