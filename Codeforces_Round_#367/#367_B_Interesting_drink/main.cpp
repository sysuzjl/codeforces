#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int x[100010];
int n;
int find(int q) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l+r)/2;
        if (x[mid] > q) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x, x+n);
    int t;
    scanf("%d", &t);
    int q;
    for (int i = 0; i < t; i++) {
        scanf("%d", &q);
        int result = find(q);
        printf("%d\n", result);
    }
    return 0;
}
