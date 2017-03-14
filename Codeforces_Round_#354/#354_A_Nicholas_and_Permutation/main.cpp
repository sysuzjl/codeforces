#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int a[105];
int absi(int x) {
    if (x < 0)
        return -x;
    return x;
}
int main() {
    int n;
    int posmin = 0;
    scanf("%d", &n);
    int posmax = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1)
            posmin = i;
        if (a[i] == n)
            posmax = i;
    }
    int maxdist = 0;
    maxdist = max(absi(posmin-0), absi(n-1-posmin));
    maxdist = max(max(maxdist, absi(posmax-0)), absi(n-1-posmax));
    printf("%d\n", maxdist);
    return 0;
}
