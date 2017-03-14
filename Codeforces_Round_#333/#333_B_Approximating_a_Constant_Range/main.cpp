#include <cstdio>
#include <algorithm>
using std::swap;
int a[100001];
int main() {
    int n, max = 0, min = 0, sum = 0, c = 1;
    scanf("%d", &n);
    scanf("%d", &a[0]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[max] <= a[i])
            max = i;
        if (a[min] >= a[i])
            min = i;
        if (a[max] - a[min] <= 1)
            c++;
        else if (max == i) {
            if (c > sum)
                sum = c;
            c = i - min;
            min = i-1;
        } else {
            if (c > sum)
                sum = c;
            c = i - max;
            max = i-1;
        }
    }
    if (c > sum)
        sum = c;
    printf("%d\n", sum);
    return 0;
}
