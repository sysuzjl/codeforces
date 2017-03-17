#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int m = 1e9+7;
int fact[1000000];
void preprocess() {
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 1000000; i++) {
        fact[i] = (fact[i-1]*1LL*i)%m;
    }
}
long long gcd(long long a, long b, long long &x, long long & y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long g = gcd (b, a%b, y, x);
    y -= a/b*x;
    return g;
}
int multiModle(int a, int b, int m) {
    return (a*1LL*b)%m;
}
int divModle(int a, int b, int m) {
    long long x, y;
    gcd(b, m, x, y);
    x = (x%m+m)%m;
    return multiModle(a, x, m);
}
int C(int a, int b, int m) {
    int ret = multiModle(fact[b], fact[a-b], m);
    return divModle(fact[a], ret, m);
}
inline int addMod(int a, int b) {
    return ((long long)a + b) % m;
}

int main() {
    string s;
    cin >> s;
    int res = 0;
    vector<int> pre(s.length(), 0);
    vector<int> suf(s.length(), 0);
    preprocess();
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            pre[i] = 1;
        if (i > 0)
            pre[i] += pre[i-1];
    }
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] == ')')
            suf[i] = 1;
        if (i < s.length()-1)
            suf[i] += suf[i+1];
    }
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == '(' && suf[i]>0) {
            if (i != 0) {
                res = addMod(res , C(pre[i-1]+suf[i], pre[i-1]+1, m));
            } else {
                res = addMod(res , C(suf[i], 1, m));
            }
        }
    }
    printf("%d\n", res);
    return 0;
}