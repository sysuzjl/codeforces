#include <iostream>
int n, h, k, a;
long long  sum = 0;
int remain = 0;
int main(int argc, const char * argv[]) {
    scanf("%d%d%d", &n, &h, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (remain + a > h) {
            remain = 0;
            sum++;
        }
        remain += a;
        sum += remain/k;
        remain = remain%k;
    }
    if (remain > 0) {
        sum += remain/k;
        remain = remain%k;
        if (remain > 0)
            sum++;
    }
    printf("%I64d\n", sum);
    return 0;
}
