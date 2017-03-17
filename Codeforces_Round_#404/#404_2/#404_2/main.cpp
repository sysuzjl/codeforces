#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int min1, min2;
int max1, max2;
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp, tmp1;
        scanf("%d%d", &tmp, &tmp1);
        if (i == 0) {
            min1 = tmp1;
            max1 = tmp;
        } else {
            min1 = min(tmp1, min1);
            max1 = max(tmp, max1);
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int tmp, tmp1;
        scanf("%d%d", &tmp, &tmp1);
        if (i == 0) {
            min2 = tmp1;
            max2 = tmp;
        } else {
            min2 = min(tmp1, min2);
            max2 = max(tmp, max2);
        }
    }
    int ret = max(max2 - min1, max1-min2);
    if (ret > 0)
        printf("%d\n", ret);
    else
        printf("0\n");
    return 0;
}