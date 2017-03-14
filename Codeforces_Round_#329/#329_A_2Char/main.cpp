#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define cls(a, n) memset(a, n, sizeof(a))
#define REP(i, n) rep(i, 0, n)
#define inf 0x7ffffffff
#define rep(i, l, n) for (int i = l; i < n; i++)
typedef long long LL;
const int maxn = 1000*100+10;
int n;
char s[1012];
int ch[26][26];
int main() {
    scanf ("%d", &n);
    int sum = 0, flag = 0;
    rep(i, 0, 26)
    cls(ch[i], 0);
    REP(i,n) {
        int c1 = -1, c2 = -1;
        scanf("%s", s);
        flag = 0;
        int len = strlen(s);
        c1 = s[0]  - 'a';
        rep(j, 0, len) {
            if (c1 == s[j] - 'a' || c2 == s[j] -'a') {
                continue;
            } else if (c2 == -1) {
                c2 = s[j] - 'a';
            } else {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        else {
            if (c2 == -1) {
                for (int i = 0; i < 26; i++) {
                    if (i != c1) {
                        ch[c1][i] += len;
                        ch[i][c1] += len;
                        sum = max(sum, ch[i][c1]);
                    }
                }
            } else {
                ch[c1][c2] += len;
                ch[c2][c1] += len;
                sum = max(sum, ch[c2][c1]);
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
