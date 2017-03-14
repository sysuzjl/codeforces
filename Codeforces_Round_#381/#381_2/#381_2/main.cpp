#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[104];
int cnt[104];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[i] = 0;
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int tmp = 0;
        for (int j = l; j <= r; j++) {
            tmp += a[j];
        }
        if (tmp > 0)
            sum+=tmp;
    }
    printf("%d\n", sum);
    return 0;
}