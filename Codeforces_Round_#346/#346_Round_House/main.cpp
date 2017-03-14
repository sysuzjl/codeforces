#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace  std;
int main() {
    int a, b, n;
    scanf("%d%d%d", &n, &a, &b);
    int dest = b%n;
    if (dest >= 0) {
        if ((a+dest)%n == 0)
            printf("%d\n", n);
        else
            printf("%d\n", (a+dest)%n);
    } else {
        dest += n;
        if ((a+dest)%n == 0)
            printf("%d\n", n);
        else
            printf("%d\n", (a+dest)%n);
    }
    return 0;
}
