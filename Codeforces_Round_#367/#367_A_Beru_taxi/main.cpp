#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int a, b, n;
int x, y, v;

int main() {
    scanf("%d%d", &a, &b);
    scanf("%d", &n);
    double mintime;
    int flag  = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &x, &y, &v);
        if (flag) {
            mintime = sqrt((x-a)*(x-a)+(y-b)*(y-b))/1.0/v;
            flag = 0;
        } else {
            mintime = min(mintime,sqrt((x-a)*(x-a)+(y-b)*(y-b))/1.0/v);
        }
    }
    printf("%lf\n", mintime);
    
    
    return 0;
}
