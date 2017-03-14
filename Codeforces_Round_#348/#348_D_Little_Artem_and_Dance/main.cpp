#include <cstdio>
using namespace std;
int a[1000010];
int n, q;
int main() {
    int type, x;
    int pose = 2, poso = 1;
    scanf("%d%d", &n, &q);
    int even = 2, odd = 1;
    for (int i = 0; i < q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            pose = (pose+x+n)%n;
            poso = (poso+x+n)%n;
        } else {
            if (pose % 2 == 0) {
                pose = (pose-1 + n)%n;
                poso = (poso+1 + n)%n;
            } else {
                pose = (pose+1 + n)%n;
                poso = (poso-1 + n)%n;
            }
        }
    }
    for (int i = 0; i < n/2; i++) {
        a[pose] = even;
        a[poso] = odd;
        pose = (pose+2 + n)%n;
        poso = (poso+2 + n)%n;
        even += 2;
        odd += 2;
    }
    for (int i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[0]);
    return 0;
}
