#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int a[200010];
int maxr = 0x7fffffff, cnt = 0;
int r[200010], b[200010], op[200010];
bool comp(int a, int b) {
    return a > b;
}
int main() {
    int n, m, opp, dd;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d",&opp, &dd);
        while (cnt > 0 && r[cnt-1] <= dd) {
            cnt--;
        }
        r[cnt] = dd;
        op[cnt++] = opp;
    }
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    sort(b, b+r[0]);
    int br = r[0]-1, bl = 0;
    for (int j = 1; j < cnt; j++) {
        for (int i = r[j-1]-1; i>= r[j]; i--) {
            if (op[j-1] == 1)
                a[i] = b[br--];
            else
                a[i] = b[bl++];
        }
    }
    for (int i = r[cnt-1]-1; i>= 0; i--) {
        if (op[cnt-1] == 1)
            a[i] = b[br--];
        else
            a[i] = b[bl++];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}
