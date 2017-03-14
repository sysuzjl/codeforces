#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int main() {
    int n;
    long long sum = 0;
    int maxa = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        maxa = max(a[i], maxa);
    }
    sum -= maxa;
    if (maxa > sum)
        printf("%I64d\n", maxa - sum + 1);
    else
        printf("%I64d\n", sum - maxa + 1);
    return 0;
}
