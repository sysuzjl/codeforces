#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a, b, c, n, t, flag = 0;
int z[7];
int s[7];
int main() {
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    s[0] = a;
    s[1] = b;
    s[2] = c;
    sort(s, s+3);
    a = s[0];
    b = s[1];
    c = s[2];
    s[3] = a+b;
    s[4] = a+c;
    s[5] = b+c;
    s[6] = a+b+c;
    sort(s, s+7);
    memset(z, 0, sizeof(z));
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        for (int j = 0; j < 7; j++) {
            if (t <= s[j]) {
                z[j]++;
                break;
            }
        }
        if (t > s[6])
            flag = 1;
    }
    if (flag) {
        printf("-1\n");
        return 0;
    }
    int ans = z[6], extra, extraa;
    ans += z[5];
    z[0] -= min(z[5], z[0]);
    ans += z[4];
    extra = z[4] - z[1];
    z[1] -= z[4];
    if (z[1] < 0) {
        z[1] = 0;
        extra = min(z[0], extra);
        z[0] -= extra;
    }
    if (a+b > c) {
        ans += z[3];
        extra = z[3] - z[2];
        extraa = extra-z[1];
        z[2] -= min(z[2], z[3]);
        if (extra > 0) {
            z[1] -= min(extra, z[1]);
        }
        if (extraa > 0) {
            z[0] -= min(extraa, z[0]);
        }
        z[3] = 0;
    }
    int x = z[0]+z[1]+z[2];
    int y = z[3];
    int count = ans;
    ans = 0x7fffffff;
    for (int i = 0; i <= n; i++) {
        ans = min(ans,  count + i + max((x+y+1)/2, y));
        for (int who = 1; who <= 3; who++) {
            if (who == 3) {
                if (z[who] > 0) {
                    z[3]--;
                    y--;
                    continue;
                }
            }
            for (int j = who-1; j >= 0; j--) {
                if (z[j] > 0) {
                    z[j]--;
                    x--;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
