const int maxn = 100000 + 10;
int a[maxn];
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n, cnt = 0, max1 = 0;
    scanf("%d", &n);
     a[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= a[i-1]) {
            cnt++;
            max1 = max(cnt, max1);
        } else {
            cnt = 1;
        }
    }
    printf("%d\n", max1);
    return 0;
}
