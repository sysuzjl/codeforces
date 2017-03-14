
#include <iostream>
#include <cstdio>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b/2)
        a = b/2;
    if (a > c/4)
        a = c/4;
    printf("%d\n", a*7);
    return 0;
}
