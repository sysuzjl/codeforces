#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace  std;
struct Point {
    int x;
    int y;
};
Point  p[1010];
int main() {
    int n, counti = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    for (int i = 1; i < n; i++) {
        if (p[i].x == p[i-1].x && p[i].y < p[i-1].y) {
            if (p[i+1].x > p[i].x)
                counti++;
        }
        else if (p[i].x == p[i-1].x && p[i].y > p[i-1].y) {
            if (p[i+1].x < p[i].x)
                counti++;
        } else if (p[i].y == p[i-1].y && p[i].x > p[i-1].x) {
            if (p[i+1].y > p[i].y)
                counti++;
        } else if (p[i].y == p[i-1].y && p[i].x < p[i-1].x) {
            if (p[i+1].y < p[i].y)
                counti++;
        }
    }
    printf("%d\n",  counti);
    return 0;
}
