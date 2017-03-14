#include <iostream>
long long sum = 0;
int mino = 0x7fffffff;
int main(int argc, const char * argv[]) {
    int n, x;
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 != 0)
            flag++;
        if (x % 2 != 0 && x < mino)
            mino = x;
        sum += x;
    }
    if (flag % 2 != 0)
        sum -= mino;
    printf("%lld\n", sum);
    return 0;
}
