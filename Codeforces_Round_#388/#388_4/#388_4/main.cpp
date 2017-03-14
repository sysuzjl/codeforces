#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
struct bid {
    int index;
    int m;
    friend bool operator< (bid a, bid b) {
        return a.m < b.m;
    }
};
bid a[200000];
int mapa[200000];
int storea[200000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].index = i+1;
        a[i].m = 0;
        mapa[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x-1].m = y;
    }
    sort(a, a+n);
    int q, k;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        int tmp;
        for (int i = 0; i < k; i++) {
            scanf("%d", &tmp);
            mapa[tmp] = 1;
            storea[i] = tmp;
        }
        int j;
        for (j = n-1; j >= 0; j--) {
            if (mapa[a[j].index] != 1)
                break;
        }
        if (j >= 0 && a[j].m != 0)
            printf("%d %d\n", a[j].index, a[j].m);
        else
            printf("0 0\n");
        for (int i = 0; i < k; i++) {
            mapa[storea[i]] = 0;
        }
    }
    
    
    return 0;
}