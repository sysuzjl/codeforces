#include <cstdio>
#include <algorithm>
using std::swap;
using std::max;
long long suma = 0, sumb = 0;
int a[11], b[11];
int main() {
    int x, y, n, m;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        suma = suma * x + a[i];
    }
    scanf("%d%d", &m, &y);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        sumb = sumb * y + b[i];
    }
    if (suma == sumb)
        printf("=\n");
    else if(suma < sumb)
        printf("<\n");
    else
        printf(">\n");
    return 0;
}
