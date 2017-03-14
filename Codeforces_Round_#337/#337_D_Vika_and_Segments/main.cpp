#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
struct lines {
    int x1;
    int x2;
    int h;
    int flag;
    friend bool operator< (lines a, lines b) {
        return a.h < b.h;
    }
};
long long cover[maxn<<4], sum[maxn<<4];
int w[maxn<<2], tot = 0, lenx = 0;
lines edges[maxn<<2];
void add_edge(int x, int x1, int h, int cover) {
    edges[tot].x1 = x;
    edges[tot].x2 = x1;
    edges[tot].h = h;
    edges[tot++].flag = cover;
}
void unite() {
    int k = lenx;
    lenx = 1;
    for (int i = 1; i < k; i++) {
        if (w[i] != w[i-1]) {
            w[lenx++] = w[i];
        }
    }
}
int binary_find(int x) {
    int l = 0, r = lenx;
    while (l <= r) {
        int mid = (l+r)/2;
        if (w[mid] == x)
            return mid;
        else if (w[mid] < x)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}
void maintain(int l, int r, int root) {
    if (cover[root] > 0) {
        sum[root] = w[r] - w[l];
    } else if (l == r-1) {
        sum[root] = 0;
    } else {
        sum[root] = sum[root<<1] + sum[root<<1 | 1];
    }
}
void query(int L, int R, int flag, int l, int r, int root) {
    if (L <= l && r <= R) {
        cover[root] += flag;
        maintain(l, r, root);
        return;
    } else if (r-1 == l) {
        return;
    }
    int mid = (l+r)/2;
    if (mid >= L) query(L, R, flag, l, mid, root << 1);
    if (mid < R) query(L, R, flag, mid, r, (root << 1 | 1));
    maintain(l, r, root);
}
int main() {
    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    for (int i = 0;i < n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x2 < x1 || y2 < y1) {
            swap(x1, x2);
            swap(y1, y2);
        }
        x1--;
        y1--;
        add_edge(x1, x2, y1, 1);
        add_edge(x1, x2, y2, -1);
        w[lenx++] = x1;
        w[lenx++] = x2;
    }
    memset(cover, 0, sizeof(cover));
    memset(sum, 0, sizeof(sum));
    sort(w, w+lenx);
    unite();
    sort(edges, edges+tot);
    long long ans = 0;
    for (int i = 0; i < tot-1; i++) {
        int L = binary_find(edges[i].x1);
        int R = binary_find(edges[i].x2);
        query(L, R, edges[i].flag, 0, lenx-1, 1);
        ans += (edges[i+1].h - edges[i].h) * sum[1];
    }
    printf("%lld\n", ans);
}
