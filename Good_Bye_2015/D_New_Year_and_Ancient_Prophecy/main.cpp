#include <cstdio>
#include <algorithm>
#include <cstring>
using std::max;
char s[5010];
int dp[5010][5010];
int nxt[5010][5010];
int summ[5010][5010];
const int module = 1e9 + 7;
int cmp(int a, int b, int c) {
    if (nxt[a][b] >= b-a) {
        return 0;
    } else {
        if (s[a+nxt[a][b]-1] < s[b+nxt[a][b]-1])
            return 1;
        else
            return 0;
    }
}
int main() {
    int d, a;
    scanf("%d", &d);
    scanf("%s", s);
    memset(dp, 0, sizeof(dp));
    memset(nxt, 0, sizeof(nxt));
    memset(summ, 0, sizeof(summ));
    for (int i = 0;i <= d; i++) {
        dp[1][i] = 1;
        summ[1][i] = 1;
    }
    for (int i = d; i >= 1; i--) {
        for (int j = d; j > i; j--) {
            if (s[i-1] == s[j-1])
                nxt[i][j] = nxt[i+1][j+1] + 1;
        }
    }
    for (int j = 2; j <= d; j++) {
        for (int i = 2; i <= j; i++) {
            a = max(1, 2*i-j);
            if (s[i-1] == '0') {
                dp[i][j] = 0;
                summ[i][j] += summ[i-1][j];
                continue;
            }
            dp[i][j] = (summ[i-1][i-1]-summ[a-1][i-1]) % module;
            if (dp[i][j] < 0)
                dp[i][j] += module;
            if (a > 1) {
                int flag = cmp(a-1, i, j);
                if (flag == 1) {
                    dp[i][j] = (dp[i][j] + dp[a-1][i-1]) %module;
                }
            }
            summ[i][j] += (summ[i-1][j] + dp[i][j]) % module;
        }
    }
    int sum = 0;
    for (int i = 1; i <= d; i++) {
        sum = (sum + dp[i][d]) % module;
    }
    printf("%d\n", sum);
    return 0;
}
