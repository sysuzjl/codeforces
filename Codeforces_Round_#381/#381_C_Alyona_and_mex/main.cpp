#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[100005];
int l[100005];
int r[100005];
int main() {
    int n, m;
    int mex = 1e9+2;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        mex = min(r-l+1, mex);
    }
    int interval = mex-1;
    int  i  = 0;
    printf("%d\n", mex);
    while (i < n) {
        for (int j = 0; j <= interval && i < n; j++) {
            if (i != n-1)
                printf("%d ", j);
            else
                printf("%d\n", j);
            i++;
        }
    }
    return 0;
}

