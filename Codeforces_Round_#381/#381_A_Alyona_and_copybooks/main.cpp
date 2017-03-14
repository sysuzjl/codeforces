#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long n, a, b, c;
    scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
    int k = 4-n%4;
    if (k == 1) {
        printf("%I64d\n", min(min(a, b+c), 3*c));
    } else if (k == 0 || k == 4) {
        printf("0\n");
    } else if (k == 2) {
        printf("%I64d\n", min(min(2*a, b), c*2));
    } else {
        printf("%I64d\n", min(min(c, 3*a), a+b));
    }
    return 0;
}
