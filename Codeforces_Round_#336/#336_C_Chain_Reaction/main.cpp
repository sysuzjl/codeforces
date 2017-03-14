#include <cstdio>
#include <algorithm>
using namespace std;
const int maxi = 1000005;
const int maxn = 100005;
int dp[maxi];
int b[maxi], maxs = 0;
int main() {
    int n, a, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &t);
        b[a] = t;
    }
    if (b[0] > 0)
        dp[0] = 1;
    for (int i = 1; i < maxi; i++) {
        if (!b[i])
            dp[i] = dp[i-1];
        else if (b[i] >= i)
            dp[i] = 1;
        else
            dp[i] = dp[i-b[i]-1] + 1;
        if (dp[i] > maxs) {
            maxs = dp[i];
        }
    }
    printf("%d\n", n-maxs);
    return 0;
}
