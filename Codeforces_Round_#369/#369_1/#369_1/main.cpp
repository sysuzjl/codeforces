//
//  main.cpp
//  #369_1
//
//  Created by zhoujl on 16/8/29.
//  Copyright (c) 2016年 zhoujl. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int n, m, k;
int Color[102];
int p[102][102];
int tmpCol[102];
int minp[102];
int minCol[102];
int Index[102];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    int cntCol = 0;
    int len = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &Color[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (Color[i] != 0 && i != 0 && Color[i] != Color[i-1])
            cntCol++;
        else if (i == 0 && Color[i] != 0)
            cntCol++;
        else if (Color[i] == 0) {
            tmpCol[len] = i;
            minp[len] = 1e9+2;
            for (int j = 1; j <= m; j++) {
                if (tmpCol[len] != 0 && j != Color[tmpCol[len] - 1] && tmpCol[len] != n-1 && j != Color[tmpCol[len] + 1]) {
                    if (minp[len] > p[tmpCol[len]][j]) {
                        minCol[len] = j;
                    }
                    minp[len] = min(minp[len], p[tmpCol[len]][j]);
                }
                else if (tmpCol[len] == 0 && tmpCol[len] != n-1 && j != Color[tmpCol[len] + 1]) {
                    if (minp[len] > p[tmpCol[len]][j]) {
                        minCol[len] = j;
                    }
                    minp[len] = min(minp[len], p[tmpCol[len]][j]);
                } else if (tmpCol[len] == n-1 && j != Color[tmpCol[len] - 1]) {
                    if (minp[len] > p[tmpCol[len]][j]) {
                        minCol[len] = j;
                    }
                    minp[len] = min(minp[len], p[tmpCol[len]][j]);
                }
            }
            if (minp[len] == 1e9+2) {
                if (m == 2) {
                    if (p[tmpCol[len]][0] < p[tmpCol[len]][1]) {
                        Color[i] = 0;
                    } else {
                        Color[i] = 1;
                    }
                    res += min(p[tmpCol[len]][0], p[tmpCol[len]][1]);
                } else {
                    res += p[tmpCol[len]][0];
                    Color[i] = 0;
                }
            } else {
                len++;
            }
        }
    }
    int tmpk = k-cntCol;
    if (tmpk < 0 || tmpk > len) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        Index[i] = i;
    }
    for (int i = 0; i < len-1; i++) {
        for (int j = i; j < len-i-1; j++) {
            if (minp[Index[j]] > minp[Index[j+1]])
                swap(Index[j], Index[j+1]);
        }
    }
    for (int i = 0; i < tmpk; i++) {
        res += minp[Index[i]];
        Color[tmpCol[Index[i]]] = minCol[Index[i]];
    }
    for (int i = tmpk; i < len; i++) {
        if (tmpCol[tmpk] > 0 && tmpCol[tmpk] < n-1) {
            if (p[tmpCol[tmpk]][Color[tmpCol[tmpk]-1]] < p[tmpCol[tmpk]][Color[tmpCol[tmpk]+1]]) {
                res += p[tmpCol[tmpk]][Color[tmpCol[tmpk]-1]];
                Color[tmpCol[tmpk]] = Color[tmpCol[tmpk]-1];
            } else {
                res += p[tmpCol[tmpk]][Color[tmpCol[tmpk]+1]];
                Color[tmpCol[tmpk]] = Color[tmpCol[tmpk]+1];
            }
        } else if (tmpCol[tmpk] == 0) {
            res += p[tmpCol[tmpk]][Color[tmpCol[tmpk]+1]];
            Color[tmpCol[tmpk]] = Color[tmpCol[tmpk]+1];
        } else {
            res += p[tmpCol[tmpk]][Color[tmpCol[tmpk]-1]];
            Color[tmpCol[tmpk]] = Color[tmpCol[tmpk]-1];
        }
    }
    printf("%lld\n", res);
    
    
    return 0;
}
