#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
#define rep(i, l, n) for (int i = l; i < n; i++)
long long a, b;
int lena = 0, lenb = 0, suma = 0, sumb = 0;
int counta[68], countb[68], l = 0, r = 0, flag = 0;
int main() {
    scanf("%lld%lld", &a, &b);
    a--;
    long long t = a;
    int l = 0, r = 0;
    for (long long i = 1; i <= a; i = i*2, lena++) {
        counta[l++] = t%2;
        flag += 1-(t%2);
        t /= 2;
    }
    t = b;
    if (flag == 1)
        suma++;
    flag = 0;
    for (long long i = 1; i <= b; i = i*2, lenb++) {
        countb[r++] = t%2;
        flag += 1-(t%2);
        t /= 2;
    }
    if (flag == 1)
        sumb++;
    l--;
    r--;
    for (int i = l-1; i >= 0; i--) {
        if (counta[i] == 1)
            suma++;
        else
            break;
    }
    for (int i = r-1; i >= 0; i--) {
        if (countb[i] == 1)
            sumb++;
        else
            break;
    }
    if (lena > 1)
    suma += (lena-1)*(lena-2)/2;
    if (lenb > 1)
    sumb += (lenb-1)*(lenb-2)/2;
    printf("%d\n", sumb-suma);
    return 0;
}
