#include <cstdio>
#include <cstring>
const int maxn = 200010;
int n, m, k, L, R, t, countn = 0;
char s[200050];
char op[15], cc;
int rson[maxn<<2], rt[maxn<<2], lson[maxn<<2];
int tot[maxn<<2];
char b[256];
void pushup(int root) {
    int ls = root << 1;
    int rs = root << 1 | 1;
    rson[root] = rson[rs];
    lson[root] = lson[ls];
}
void build(int l, int r, int root) {
    tot[root] = r-l+1;
    if (l == r) {
        rson[root] = lson[root] = rt[root] = s[l];
        return;
    }
    int mid = l + (r - l)/2;
    build(l, mid, root<<1);
    build(mid+1, r, root<<1|1);
    pushup(root);
}
void pushdown(int root) {
    if (rt[root] > 0) {
        int ls = root << 1;
        int rs = root << 1 | 1;
        rson[rs] = lson[rs] = rt[rs] = rt[root];
        rson[ls] = lson[ls] = rt[ls] = rt[root];
        rt[root] = 0;
    }
}

void setv(int l, int r, int root) {
    if (L <= l && r <= R) {
        rson[root] = lson[root] = rt[root] = cc;
        return;
    }
    pushdown(root);
    int mid = l + (r - l)/2;
    if (mid >= L)
        setv(l, mid, root<<1);
    if (mid < R)
        setv(mid+1, r, root<<1|1);
    pushup(root);
}
int query(int l, int r, int root) {
    if (rt[root] > 0 || l == r) {
        return tot[root];
    }
    int mid = l + (r - l)/2;
    int lret = query(l, mid, root<<1);
    int rret = query(mid+1, r, root<<1|1);
    int ret = lret + rret;
    int ls = root<<1;
    int rs = root<<1|1;
    if (b[rson[ls]] < b[lson[rs]])
        --ret;
    return ret;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    int len = strlen(s);
    build(0, len-1, 1);
    while (m--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &L, &R);
            L--;
            R--;
            while((cc=getchar())<'a' || cc>'z');
            setv(0, len-1, 1);
        } else {
            scanf("%s", op);
            int len1 = strlen(op);
            for (int i = 0; i < len1; i++) {
                b[op[i]] = i;
            }
            printf("%d\n", query(0, len-1, 1));
        }
    }
}
