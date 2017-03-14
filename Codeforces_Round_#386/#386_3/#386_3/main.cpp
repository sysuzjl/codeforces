#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    int s, x1, x2;
    int t1, t2;
    int p, d, d1;
    scanf("%d%d%d", &s, &x1, &x2);
    scanf("%d%d", &t1, &t2);
    scanf("%d%d", &p, &d);
    if (x1 < x2) {
        d1 = 1;
    } else {
        d1 = -1;
    }
    if (t2 < t1) {
        if (d1 == 1)
            printf("%d\n", (x2-x1)*t2);
        else
            printf("%d\n", (x1-x2)*t2);
    } else {
        int res_t1, res_t2;
        if (d1 == 1) {
            res_t1 = (x2 - x1)*t2;
        } else {
            res_t1 = (x1 - x2)*t2;
        }
        if (d1 == 1 && d == 1) {
            if (p <= x1) {
                res_t2 = (x2-p)*t1;
            } else {
                res_t2 = (x2-x1)*t1 + (s*2 - p + x1) * t1;
            }
        } else if (d1 == -1 && d == -1){
            if (p >= x1) {
                res_t2 = (p-x2)*t1;
            } else {
                res_t2 = (x1-x2)*t1 + (s*2 + p - x1) * t1;
            }
        } else if (d1 == 1 && d == -1) {
            res_t2 = (x2-x1)*t1 + (p+x1) * t1;
        } else {
            res_t2 = (x1-x2)*t1 + (s-p+s-x1) * t1;
        }
        if (res_t2 > res_t1) {
            printf("%d\n", res_t1);
        } else {
             printf("%d\n", res_t2);
        }
    }
    
    return 0;
}