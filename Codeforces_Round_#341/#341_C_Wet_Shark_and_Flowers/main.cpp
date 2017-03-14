#include <cstdio>
#include <cstring>
using namespace std;
double sum = 0;
int counts[100010], countp[100010];
int main() {
    int x, y, p, n;
    scanf("%d%d", &n, &p);
    for (int i  = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        counts[i] = y-x+1;
        countp[i] = y/p - x/p;
        if (x % p == 0)
            countp[i]++;
    }
    counts[n] = counts[0];
    countp[n] = countp[0];
    for (int i  = 0; i < n; i++) {
        sum +=  countp[i]*1.0/counts[i]*4000-countp[i]*1.0/counts[i]*countp[i+1]/counts[i+1]*2000;
    }
    printf("%.10lf\n", sum);
    return 0;
}
