#include <algorithm>
#include <cstdio>
#include <cstring>
const int maxn = 55;
struct node {
    int h;
    int v;
};
node a[maxn*maxn];
int vish[maxn*maxn], visv[maxn*maxn];
int main() {
    int n;
    scanf("%d", &n);
    memset(vish, 0, sizeof(vish));
    memset(visv, 0, sizeof(visv));
    for (int i = 0; i < n*n; i++) {
        scanf("%d%d", &a[i].h, &a[i].v);
    }
    for (int i = 0; i < n*n; i++) {
        if (!vish[a[i].h] && !visv[a[i].v]) {
            printf("%d ", i+1);
            vish[a[i].h] = 1;
            visv[a[i].v] = 1;
        }
    }
    return 0;
}
