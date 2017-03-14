#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010], b[1010];
int main() {
    int n;
    scanf("%d", &n);
    int d1 = 0, d2 = 0;
    long long maxt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        d1 = a[i];
        d2 = b[i];
        maxt = max(d1+1LL+d2-1, maxt);
        for (int j = i+1; j < n; j++) {
            d1 |= a[j];
            d2 |= b[j];
            maxt = max(d1+1LL+d2-1, maxt);
        }
    }
    printf("%lld\n", maxt);
    return 0;
}
