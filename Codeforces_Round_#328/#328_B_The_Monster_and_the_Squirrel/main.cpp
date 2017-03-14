#include <cstdio>
int main() {
    long long n;
    scanf("%I64d", &n);
    if (n == 3)
        printf("1\n");
    else if (n == 4)
        printf("4\n");
    else
        printf("%I64d\n", (n-2)*(n-2));
    return 0;
}
