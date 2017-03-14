#include <iostream>
int n, h, sum;
int a[1010];
int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > h)
            sum += 2;
        else
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
