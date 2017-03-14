#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct point{
    int x;
    int y;
};
int a[505][505];
point pre;
int main() {
    int n, x, y, x0, y0;
    cin >> x >> y >> x0 >> y0;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i <= x; i++)
        memset(a[i], 0, sizeof(a[i]));
    a[x0][y0] = 1;
    printf("1 ");
    pre.x = x0;
    pre.y = y0;
    int c = 1;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'U') {
            if (pre.x == 1)
                printf("0 ");
            else {
                pre.x--;
                if (!a[pre.x][pre.y]) {
                    c++;
                    printf("1 ");
                    a[pre.x][pre.y] = 1;
                } else {
                    printf("0 ");
                }
            }
        } else if (s[i] == 'D') {
            if (pre.x == x)
                printf("0 ");
            else {
                pre.x++;
                if (!a[pre.x][pre.y]) {
                    c++;
                    printf("1 ");
                    a[pre.x][pre.y] = 1;
                } else {
                    printf("0 ");
                }
            }
        } else if (s[i] == 'L') {
            if (pre.y == 1)
                printf("0 ");
            else {
                pre.y--;
                if (!a[pre.x][pre.y]) {
                    c++;
                    printf("1 ");
                    a[pre.x][pre.y] = 1;
                } else {
                    printf("0 ");
                }
            }
        } else if (s[i] == 'R') {
            if (pre.y == y)
                printf("0 ");
            else {
                pre.y++;
                if (!a[pre.x][pre.y]) {
                    c++;
                    printf("1 ");
                    a[pre.x][pre.y] = 1;
                } else {
                    printf("0 ");
                }
            }
        }
    
    }
    printf("%d\n", x*y-c);
}
