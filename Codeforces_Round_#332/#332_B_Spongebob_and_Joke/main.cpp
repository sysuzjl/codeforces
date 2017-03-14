#include <cstdio>
#include <map>
using std::map;
const int maxn = 100010;
int f[maxn] = {0}, a[maxn];
int main() {
    int n, m, d, flaga = 0, flagb = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        if (f[d])
            f[d] = -1;
        else
            f[d] = i+1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &d);
        if (f[d] > 0)
            a[i] = f[d];
        else if (f[d] == -1)
            flaga = 1;
        else
            flagb = 1;
    }
    if (flagb)
        printf("Impossible\n");
    else if (flaga)
        printf("Ambiguity\n");
    else {
        printf("Possible\n");
        for (int i = 0; i < m-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[m-1]);
    }
    return 0;
}
