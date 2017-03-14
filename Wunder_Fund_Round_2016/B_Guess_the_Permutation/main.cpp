#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[55][55];
int p[55], vis[55];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= n; j++)
             scanf("%d", &a[i][j]);
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= n; j++) {
            if (a[i][j] && a[i][j] != n-1 && !vis[a[i][j]]) {
                int flag = 0;
                for (int k = 1; k <= n; k++) {
                    if (a[k][j] == a[i][j] && k != i) {
                        vis[a[i][j]] = 1;
                        p[j] = a[i][j];
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    vis[a[i][j]] = 1;
                    p[i] = a[i][j];
                }
            } else if (a[i][j] == n-1 && !vis[a[i][j]]) {
                vis[a[i][j]] = 1;
                p[i] = a[i][j];
                p[j] = n;
            }
        }
    }
    for (int i = 1; i <= n-1; i++) {
        printf("%d ", p[i]);
    }
    printf("%d\n", p[n]);
    return 0;
}
