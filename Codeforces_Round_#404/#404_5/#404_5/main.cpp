#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

using namespace std;
vector<vector<int>>a;
vector<int> b;
int block;
int btcnt;
int l[500];
int r[500];
void init(int n) {
    btcnt = sqrt(n*1.0) + 0.5;
    block = n/btcnt+1;
    a.resize(btcnt);
    for (int i = 1; i <= n; i++) {
        int loc = (i-1)/block;
        a[loc].push_back(i);
        b.push_back(i);
    }
}
int query(int l, int r) {
    if (l == r)
        return 0;
    int lid = (l-1)/block;
    int rid = (r-1)/block;
    int res = 0;
    int t1 = 0;
    int t2 = 0;
    int v = b[l-1];
    if (v < b[r-1])
        res++;
    else
        res--;
    if (lid == rid) {
        for (int i = l+1; i < r; i++) {
            if (b[i-1] > v)
                t1++;
            if (b[i-1] < b[r-1])
                t2++;
        }
        if (l+1 < r) {
            res += l+1+t1+t1-r;
            res += l+1+t2+t2-r;
        }
        return res;
    }
    t1 = 0;
    t2 = 0;
    for (int i = l+1; i <= (lid+1)*block; i++) {
        if (b[i-1] > v)
            t1++;
        if (b[i-1] < b[r-1])
            t2++;
    }
    res += l+t1+t1-(lid+1)*block;
    res += l+t2+t2-(lid+1)*block;
    t1 = 0;
    t2 = 0;
    for (int i = r-1; i > rid*block; i--) {
        if (b[i-1] > v)
            t1++;
        if (b[i-1] < b[r-1])
            t2++;
    }
    res += rid*block+t1+t1-r+1;
    res += rid*block+t2+t2-r+1;
    t1 = 0;
    t2 = 0;
    for (int i = lid+1; i < rid; i++) {
        auto it1 = lower_bound(a[i].begin(), a[i].end(), b[l-1]);
        auto it2 = lower_bound(a[i].begin(), a[i].end(), b[r-1]);
        t1 = it1 - a[i].begin();
        t2 = it2 - a[i].begin();
        res += block-t1-t1;
        res += t2+t2-block;
    }
    return res;
}
void reswap(int l ,int r) {
    if (l == r)
        return;
    swap(b[l-1], b[r-1]);
    int lid = (l-1)/block;
    int rid = (r-1)/block;
    auto it1 = lower_bound(a[lid].begin(), a[lid].end(), b[r-1]);
    a[lid].erase(it1);
    auto it2 = lower_bound(a[rid].begin(), a[rid].end(), b[l-1]);
    a[rid].erase(it2);
    it1 = lower_bound(a[lid].begin(), a[lid].end(), b[l-1]);
    a[lid].insert(it1, b[l-1]);
    it2 = lower_bound(a[rid].begin(), a[rid].end(), b[r-1]);
    a[rid].insert(it2, b[r-1]);
}
int main() {
    int n, q;
    cin >> n >> q;
    init(n);
    long long res = 0;
    while (q--) {
        int x, y;
        cin >>x >> y;
        if (x > y)
            swap(x, y);
        res += query(x,y);
        reswap(x, y);
        cout << res << endl;
    }
}