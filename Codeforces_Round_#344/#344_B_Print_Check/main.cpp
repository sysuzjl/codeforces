#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct cell {
    int x;
    int qvoit;
    cell() {
        x = 0;
        qvoit = -1;
    }
}r[5010], c[5010];

int main() {
    int n, m, k, flag, col, p;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &flag, &p, &col);
        if (flag == 1) {
            r[p].x = col;
            r[p].qvoit = i;
        } else {
            c[p].x = col;
            c[p].qvoit = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            if (r[i].qvoit < c[j].qvoit) {
                if (j == 1)
                    printf("%d", c[j].x);
                else
                    printf(" %d", c[j].x);
            } else {
                if (j == 1)
                    printf("%d", r[i].x);
                else
                    printf(" %d", r[i].x);
            }
        }
        printf("\n");
    }
    return 0;
}
