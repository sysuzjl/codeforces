#include <cstdio>
#include <cstring>
using namespace std;
long long sum;
int d[2010];
int p[2010];
int main() {
    int n, x, y;
    scanf("%d", &n);
    memset(d, 0, sizeof(d));
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        d[x-y+1000]++;
        p[x+y]++;
    }
    for (int i = 0; i <= 2004; i++) {
        if (p[i] >= 2) {
            sum += p[i] * 1LL * (p[i]-1) / 2;
        }
        if (d[i] >= 2) {
            sum += d[i] * 1LL * (d[i]-1) / 2;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
