#include <cstdio>
#include <iostream>
using namespace std;
#define PI 3.141592654
int main() {
    double d, h, v, e;
    scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
    double remaind = 4*v/(PI*d*d)-e;
    if (remaind <= 0.000001)
        printf("NO\n");
    else {
        printf("YES\n");
        printf("%lf\n", h/remaind);
    }
    
}
