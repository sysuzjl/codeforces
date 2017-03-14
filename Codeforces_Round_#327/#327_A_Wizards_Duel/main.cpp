#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for (i = 0; i < n; i++)
#define REPK(i,n,k) for (i = k; i < n; i++)
int main() {
    int p, q, l;
    double l1;
    scanf("%d", &l);
    scanf("%d%d", &p, &q);
    l1 = 3.0 * l;
    double t2 = l*1.0/(p+q);
    double t1 = l1/(p+q);
    double l3 = p*t1 - 2*t2*p;
    printf("%.4lf\n", l3);
    return 0;
}
