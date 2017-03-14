#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define rep(i, l, n) for (int i = l; i < n; i++)
int h, w, q, r1, c1, r2, c2;
char s[510][510];
int vis[510][510];
int dp[510][510];
int rowp[510][510];
int colp[510][510];
int disx[4] = {0, -1, 0, 1};
int disy[4] = {-1, 0, 1, 0};
int main() {
    scanf("%d%d", &h, &w);
    rep(i, 1, h+1) {
        scanf("%s", s[i]+1);
    }
    scanf("%d", &q);
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= h; i++) {
        if (s[i][1] == '.') {
                int x = i-1;
                if (x >= 1 && x<= h && s[x][1] == '.') {
                    dp[i][1] = dp[i-1][1]+1;
                } else {
                    dp[i][1] = dp[i-1][1];
                }
        } else
            dp[i][1] = dp[i-1][1];
    }
    for (int i = 2; i <= w; i++) {
        if (s[1][i] == '.') {
                int x = i-1;
                if (x >= 1 && x<= w && s[1][x] == '.') {
                    dp[1][i] = dp[1][i-1]+1;
                } else {
                    dp[1][i] = dp[1][i-1];
                }
        }
        else
        dp[1][i] = dp[1][i-1];
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            if (i == 1 && j==1) {
                colp[j][i] = 0;
            }
            if (s[j][i] == '.') {
                int x = j-1;
                if (x >= 1 && x<= h && s[x][i] == '.') {
                    colp[j][i] = colp[j-1][i]+1;
                } else {
                    colp[j][i] = colp[j-1][i];
                }
            } else
                colp[j][i] = colp[j-1][i];
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && j==1) {
                rowp[i][j] = 0;
            }
            if (s[i][j] == '.') {
                int x = j-1;
                if (x >= 1 && x<= w && s[i][x] == '.') {
                    rowp[i][j] = rowp[i][j-1]+1;
                } else {
                    rowp[i][j] = rowp[i][j-1];
                }
            } else
                rowp[i][j] = rowp[i][j-1];
        }
    }

    for (int i = 2; i <= h; i++) {
        for (int j = 2; j <= w; j++) {
            if (s[i][j] == '.') {
                for (int k = 0; k < 2; k++) {
                    int x = i + disx[k];
                    int y = j + disy[k];
                    if (x >= 1 && y >= 1 && s[x][y] == '.') {
                        dp[i][j] += dp[x][y]+1;
                    } else {
                        dp[i][j] += dp[x][y];
                    }
                }
                dp[i][j] -= dp[i-1][j-1];
            } else {
                for (int k = 0; k < 2; k++) {
                    int x = i + disx[k];
                    int y = j + disy[k];
                    dp[i][j] += dp[x][y];
                }
                dp[i][j] -= dp[i-1][j-1];
            }
        }
    }
    while (q--) {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        if (r1 == r2 && c1 == c2)
             printf("0\n");
        else
            printf("%d\n", dp[r2][c2]+dp[r1][c1] - dp[r2][c1] - dp[r1][c2] + rowp[r1][c2]- rowp[r1][c1] + colp[r2][c1] -colp[r1][c1]);
    }
    return 0;
}
