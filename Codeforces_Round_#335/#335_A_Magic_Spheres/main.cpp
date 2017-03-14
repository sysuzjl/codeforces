#include <cstdio>
int a[3], b[3], c[3], s = 0, d;
int main() {
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    scanf("%d%d%d", &b[0], &b[1], &b[2]);
    c[0] = a[0]-b[0];
    c[1] = a[1]-b[1];
    c[2] = a[2]-b[2];
    for (int i = 0; i < 3; i++) {
        if (c[i] > 0) {
            s += c[i]/2;
        } else if (c[i] < 0) {
            d += c[i];
        }
    }
    if (s >= -d)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
