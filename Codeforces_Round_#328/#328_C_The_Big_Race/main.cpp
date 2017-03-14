#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;
typedef long long LL;
LL n, w, b, m, sum, d;
LL gcd(LL a, LL b) {
    return b == 0? a: gcd(b, a%b);
}
int main() {
    cin >> n >> w >> b;
    if (n/w*gcd(w, b)/b > 0) {
        LL lcm = w/gcd(w, b)*b;
        sum = min(w, b)*(n/lcm) + min(n%lcm, min(w, b)-1);
    } else {
        sum = min(min(w, b) - 1, n);
    }
    d = gcd(sum, n);
    printf("%lld/%lld\n", sum/d, n/d);
    return 0;
}
