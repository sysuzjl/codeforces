#include <cstdio>
int a[200010];
int main() {
    int n, min = 0x7fffffff;
    scanf("%d", &n);
    for (int i = 0;i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < min)
            min = a[i];
    }
    int count = 0, max = 0;
    for (int i = 0;i < n; i++) {
        a[i] -= min;
        if (a[i] > 0) {
            count++;
        } else {
            if (max < count)
                max = count;
            count = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            count++;
        } else {
            if (max < count)
                max = count;
            break;
        }
    }
    long long b = (long long)(n)*(long long)(min);
    b += max;
    printf("%lld\n", b);
    return 0;
}
