//
//  main.cpp
//  #380_3
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
struct carRent{
    int c;
    int v;
}a[200100];
int g[200100];
int interval[200100];
int main() {
    int n, k, s, t;
    int price = -1;
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].c, &a[i].v);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &g[i]);
    }
    sort(g, g+k);
    for (int i = 0; i < k; i++) {
        if (i > 0)
            interval[i] = (g[i] - g[i-1])*2;
        else
            interval[i] = g[i]*2;
    }
    interval[k] = (s - g[k-1])*2;
    k++;
    if (s > t) {
        printf("%d\n", price);
    } else {
        sort(interval, interval+k);
        int delta = t-s;
        int start = k-1;
        int end = k-1;
        int maxv = interval[k-1]/2;
        while (delta > 0 && end != -1) {
            while (end != -1 && interval[end] == interval[start]) {
                end--;
            }
            int tmp;
            if (delta >= start-end) {
                tmp = delta/(start-end);
                if (end != -1 && interval[start] - tmp < interval[end]) {
                    tmp = interval[start] - interval[end];
                }
                delta -= tmp*(start-end);
                interval[start] -= tmp;
            } else {
                delta = -1;
            }
        }
        int minv = interval[start];
        if (maxv > minv)
            minv = maxv;
        int minprice = 1000000000+4;
        for (int i = 0; i < n; i++) {
            if (a[i].v >= minv && a[i].c < minprice)
                minprice = a[i].c;
        }
        if (minprice == 1000000000+4)
            minprice = -1;
        printf("%d\n", minprice);
    }
    return 0;
}
