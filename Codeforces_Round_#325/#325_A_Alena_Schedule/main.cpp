#include <cstdio>
int vis[102];
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vis[i]);
    }
    for (int i = 0; i < n; i++) {
        sum += vis[i];
        if (vis[i] == 0 && vis[i+1] == 1 && vis[i-1] == 1)
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
