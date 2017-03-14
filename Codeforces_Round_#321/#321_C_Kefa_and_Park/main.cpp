#define push_back pb
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100000;
vector<int> a[maxn];
int c[maxn];
int m, sum;
void go(int v,int pr, int k) {
    if (k > m) return;
    int ok = 1;
    for (int i = 0; i < a[v].size(); i ++) {
        if (a[v][i] != pr) {
            ok = 0;
            go(a[v][i], v, k*c[a[v][i]]+c[a[v][i]]);
        }
    }
    sum += ok;
}
int main() {
    int n, x, y;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    go(0, -1, c[0]);
    printf("%d", sum);
}
