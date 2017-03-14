#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
float a[105];
int n;
void add(int root, int level) {
    if (level > n)
        return;
    int r = level*(level+1)/2;
    int l = level*(level-1)/2 + 1;
    if (a[root] >= 1) {
        int lson = level*(level+1)/2+1;
        add(lson + root-l, level+1);
        add(lson + root-l+1, level+1);
    } else {
        int k = 1;
        for (int i = 1; i < level; i++) {
            k *= 2;
        }
        a[root] += 1.0/k;
    }
    return;
}
int main() {
    int t;
    scanf("%d%d", &n, &t);
    int i = 1;
    while (i <= t) {
        add(1, 1);
        i++;
    }
    int cnt = 0;
    for (int j = 1; j <= (n+1)*n/2; j++) {
        if (a[j] >= 1)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
