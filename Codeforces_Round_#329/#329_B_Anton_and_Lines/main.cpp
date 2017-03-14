#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define cls(a, n) memset(a, n, sizeof(a))
#define REP(i, n) rep(i, 0, n)
#define inf 0x7ffffffff
#define rep(i, l, n) for (int i = l; i < n; i++)
typedef long long LL;
const int maxn = 100010;
int n, k[maxn], b[maxn], x2, x1;
struct sum{
    LL s1;
    LL s2;
}s[maxn];
int cmp(sum a,sum b) {
    return a.s1 < b.s1;
}
int main() {
    scanf("%d", &n);
    scanf("%d%d", &x1, &x2);
    rep(i, 0, n) {
        scanf("%d%d", &k[i], &b[i]);
        s[i].s1 = LL(k[i])*x1+b[i];
        s[i].s2 = LL(k[i])*x2+b[i];
    }
    sort(s, s+n,  cmp);
    int flag = 0;
    LL maxsum = -(LL)1<<60;
    rep(i, 0, n) {
        int p = i;
        while (p < n && s[p].s1 == s[i].s1) {
            if(s[p].s2<maxsum){
                flag=1;
            }
            p++;
        }
        rep(j, i, p) {
            maxsum = max(maxsum, s[j].s2);
        }
        i=p-1;
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
