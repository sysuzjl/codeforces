#include <cstdio>
#include <algorithm>
using namespace std;
int n, s;
struct node {
    int t;
    int f;
    friend bool operator<(node c, node b) {
        return c.f > b.f;
    }
} a[105];

int main() {
    scanf("%d%d", &n, &s);
    int time = 0;
    for (int i = 0;i < n; i++) {
        scanf("%d%d", &a[i].f, &a[i].t);
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        time += s-a[i].f;
        s = a[i].f;
        if (time < a[i].t)
            time = a[i].t;
    }
    time += a[n-1].f;
    printf("%d\n", time);
    return 0;
}
