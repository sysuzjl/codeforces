#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int stage[1003][1003];
int maxr[1003];
int maxl[1003];
int maxu[1003];
int maxd[1003];

int main() {
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        maxu[i] = n;
        maxd[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        maxr[i] = -1;
        maxl[i] = m;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &stage[i][j]);
            if (stage[i][j] == 1) {
                if (maxr[i] < j) {
                    maxr[i] = j;
                }
                if (maxl[i] > j) {
                    maxl[i] = j;
                }
                if (maxu[j] > i) {
                    maxu[j] = i;
                }
                if (maxd[j] < i) {
                    maxd[j] = i;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (stage[i][j] == 0) {
                if (maxr[i] > j)
                    cnt++;
                if (maxl[i] < j)
                    cnt++;
                if (maxu[j] < i)
                    cnt++;
                if (maxd[j] > i)
                    cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
