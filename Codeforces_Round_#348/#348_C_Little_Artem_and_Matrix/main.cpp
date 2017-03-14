#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct op {
    int type;
    int r;
    int c;
    int x;
}p[10010];
int n, m, q;
int a[105][105];
void reverse_row(int r) {
    int t = a[r][m];
    for (int i = m; i > 1; i--) {
        a[r][i] = a[r][i-1];
    }
    a[r][1] = t;
}
void reverse_col(int c) {
    int t = a[n][c];
    for (int i = n; i > 1; i--) {
        a[i][c] = a[i-1][c];
    }
    a[1][c] = t;
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; i++) {
        scanf ("%d", &p[i].type);
        if (p[i].type == 3) {
            scanf("%d%d%d", &p[i].r, &p[i].c, &p[i].x);
        } else if(p[i].type == 2)  {
           scanf("%d", &p[i].c);
        } else {
           scanf("%d", &p[i].r);
        }
    }
    for (int i = q-1; i >= 0; i--) {
        if (p[i].type == 3) {
            a[p[i].r][p[i].c] = p[i].x;
        } else if (p[i].type == 2){
            reverse_col(p[i].c);
        } else {
            reverse_row(p[i].r);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == 1)
                printf("%d", a[i][j]);
            else
                printf(" %d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
