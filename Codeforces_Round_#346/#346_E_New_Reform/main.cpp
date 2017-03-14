#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int head[100010];
struct edge {
    int u;
    int v;
    int next;
};
edge e[200010];
int visit[100010];
int countt = 0;
int len = 0;
int flag = 0;
void add(int u, int v) {
    e[len].u = u;
    e[len].v = v;
    e[len].next = head[u];
    head[u] = len++;
    e[len].u = v;
    e[len].v = u;
    e[len].next = head[v];
    head[v] = len++;
}
void dfs(int x, int pre) {
    for (int i = head[x]; i != -1; i = e[i].next) {
        if (!visit[e[i].v] && e[i].v != pre) {
            visit[e[i].v] = 1;
            dfs(e[i].v,  e[i].u);
        } else if (e[i].v != pre) {
            flag = 0;
        }
    }
}
int main() {
    for (int i = 0; i < 100010; i++)
        head[i] = -1;
    memset(visit, 0, sizeof(visit));
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            flag = 1;
            visit[i] = 1;
            dfs(i, -1);
            countt += flag;
        }
    }
    printf("%d\n", countt);
    return 0;
}
