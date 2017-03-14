#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
char s[500010];
int a[500010];
int c[500010];
const int module = 1e9 + 7;
int n, h, w;
int main() {
    scanf("%d%d%d", &n, &h, &w);
    scanf("%s", s);
    int minx = 0, miny = 0, maxx = 0, maxy = 0,flag = 0;
    int x = 0, y = 0;
    int ans = 0,  count = 0;
    long long  moves = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            x--;
            if (minx > x) {
                ans = (ans+ moves * h % module) % module;
                w--;
                a[count++] = 1;
            }
            minx = min(x, minx);
        } else if (s[i] == 'R') {
            x++;
            if (maxx < x) {
                ans = (ans + moves * h % module) % module;
                w--;
                a[count++] = 2;
            }
            maxx = max(x, maxx);
        } else if (s[i] == 'U') {
            y++;
            if (maxy < y) {
                h--;
                ans = (ans + moves * w % module) % module;
                a[count++] = 3;
            }
            maxy = max(y, maxy);
        } else {
            y--;
            if (miny > y) {
                h--;
                ans = (ans + moves * w % module) % module;
                a[count++] = 4;
            }
            miny = min(y, miny);
        }
        if (w == 0 || h == 0) {
            flag = 1;
            break;
        }
        moves++;
    }
    if (x == 0 && y == 0 && !flag) {
        printf("-1\n");
    } else {
        count = 0;
        if (flag) { // 无判断是否已达到退出情况导致time limits
            printf("%d\n", ans);
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                x--;
                if (minx > x) {
                    ans = (ans+ moves * h % module) % module;
                    w--;
                    c[count] = moves%n;
                    a[count++] = 1;
                }
                minx = min(x, minx);
            } else if (s[i] == 'R') {
                x++;
                if (maxx < x) {
                    ans = (ans+ moves * h% module) % module;
                    w--;
                    c[count] = moves%n;
                    a[count++] = 2;
                }
                maxx = max(x, maxx);
            } else if (s[i] == 'U') {
                y++;
                if (maxy < y) {
                    h--;
                    ans = (ans + moves * w % module) % module;
                    c[count] = moves%n;
                    a[count++] = 3;
                }
                maxy = max(y, maxy);
            } else {
                y--;
                if (miny > y) {
                    h--;
                    ans = (ans + moves * w % module) % module;
                    c[count] = moves%n;
                    a[count++] = 4;
                }
                miny = min(y, miny);
            }
            if (count > 0 && c[count-1] % n == 0)
                c[count-1] = n;
            if (w == 0 || h == 0) { // 第二次循环时无判断是否已达到退出情况导致time limits
                flag = 1;
                break;
            }
            moves++;
        }
        if (flag) {
            printf("%d\n", ans);
            return 0;
        }
        int i = 0;
        long long k = 2;
        while (h != 0 && w != 0) {
            if (a[i] == 1) {
                w--;
                ans = (ans + (k * n % module + c[i]) * h % module)% module;
            } else if (a[i] == 2) {
                w--;
                ans = (ans + (k * n % module + c[i]) * h % module)% module;
            } else if (a[i] == 3) {
                h--;
                ans = (ans + (k * n % module + c[i]) * w % module)% module;
            } else {
                h--;
                ans = (ans + (k * n % module + c[i]) * w % module)% module;
            }
            if (i == count-1) {
                i = 0;
                k++;
            }
            else
                i++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
