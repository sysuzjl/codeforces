#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main() {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    scanf("%d%d", &x3, &y3);
    double centx1, centy1, centx2, centy2, centx3, centy3;
    centx1 = (x1+x2)/2.0;
    centy1 = (y1+y2)/2.0;
    centx2 = (x1+x3)/2.0;
    centy2 = (y1+y3)/2.0;
    centx3 = (x3+x2)/2.0;
    centy3 = (y3+y2)/2.0;
    printf("3\n");
    printf("%d %d\n", (int)(2*centx1-x3), (int)(2*centy1-y3));
    printf("%d %d\n", (int)(2*centx2-x2),  (int)(2*centy2-y2));
    printf("%d %d\n", (int)(2*centx3-x1),  (int)(2*centy3-y1));
    return 0;
}
