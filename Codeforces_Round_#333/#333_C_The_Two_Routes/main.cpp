#include <cstdio>
#include <algorithm>
#include <queue>
using std::queue;
int v[405][405] = {0}, n, m, a, b, d[405] = {0}, c[405] = {0}, flag = 0, flag1 = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }
    queue<int> node;
    queue<int> nodea;
    node.push(1);
    while (!node.empty()){
        int i = node.front();
        node.pop();
        for (int j = 1; j <= n; j++) {
            if (j != i && v[i][j] == 0) {
                v[i][j] = 2;
                v[j][i] = 2;
                node.push(j);
                if (d[j] != 0 && d[j] > d[i]+1)
                    d[j] = d[i] + 1;
                else if (d[j] == 0)
                    d[j] = d[i] + 1;
                if (j == n) {
                    flag = 1;
                    break;
                }
            }
        }
    }
    nodea.push(1);
    while (!nodea.empty()){
        int i = nodea.front();
        nodea.pop();
        for (int j = 1; j <= n; j++) {
            if (j != i && v[i][j] == 1) {
                v[i][j] = 2;
                v[j][i] = 2;
                nodea.push(j);
                if (c[j] != 0 && c[j] > c[i]+1)
                    c[j] = c[i] + 1;
                else if (c[j] == 0)
                    c[j] = c[i] + 1;
                if (j == n) {
                    flag1 = 1;
                    break;
                }
            }
        }
    }
    if (flag &&flag1)
        printf("%d\n", d[n] > c[n]? d[n] : c[n]);
    else
        printf("-1\n");
    return 0;
}
