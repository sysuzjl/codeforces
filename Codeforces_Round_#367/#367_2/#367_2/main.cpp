//
//  main.cpp
//  #367_2
//
//  Created by zhoujl on 16/8/12.
//  Copyright (c) 2016年 zhoujl. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int c[100010];
string s, s1;
string reverse() {
    string rs = "";
    for (int i = s.length()-1; i >= 0; i--) {
        rs += s[i];
    }
    return rs;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    cin>>s;
    string rs1 = reverse();
    string line2, line1;
    int cnt = 0;
    int cnt1 = 0;
    if (rs1 >= s) {
        line1 = s;
        line2 = s;
    } else {
        line1 = s;
        line2 = rs1;
        cnt1 = c[0];
    }
    for (int i = 1; i < n; i++) {
        int flag = 0, flag1 = 0;
        cin>>s;
        string rs = reverse();
        if (line1 == line2) {
            cnt = cnt<cnt1?cnt:cnt1;
            cnt1 = cnt;
            if (rs1 >= s) {
                line1 = s;
                line2 = s;
            } else {
                line1 = s;
                line2 = rs1;
                cnt1 += c[i];
            }
        }
        if (s >= line1) {
            line1 = s;
        } else if (s < line1 && rs >= line1) {
            line1 = rs;
            cnt += c[i];
        } else {
            flag = 1;
        }
        if (s >= line2) {
            line2 = s;
        } else if (s < line2 && rs >= line2) {
            line2 = rs;
            cnt1 += c[i];
        } else {
            flag1 = 1;
        }
        if (flag == 1 && flag1 == 1) {
            printf ("-1\n");
        }
    }
    printf("%d\n", cnt<cnt1?cnt:cnt1);
    return 0;
}