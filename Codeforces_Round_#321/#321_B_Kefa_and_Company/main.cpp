#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
long long max(long long  a, long long b) {
    if (a > b)
        return a;
    return b;
}
const int maxn = 100000+10;
struct Friend {
    int m;
    int s;
};
int cmp(Friend a, Friend b) {
    return a.m < b.m;
}
long long f[maxn];
int main() {
    int n, d;
    long long max1 = 0;
    Friend com[100010];
    com[0].m = 0;
    com[0].s = 0;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &com[i].m, &com[i].s);
    }
    int j = 1;
    sort(&com[1], com+n+1, cmp);
    f[0] = 0;
    max1 = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i-1]+com[i].s;
        max1 = max(com[i].s, max1);
        while (com[i].m-com[j].m >= d) {
            j++;
        }
        max1 = max(f[i]-f[j-1], max1);
    }
    printf("%I64d\n", max1);
    return 0;
}
