#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
long long k;
int id[100010];
int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }
    if (n == 1)
        printf("%d\n", id[0]);
    else {
        long long sn = 1;
        while (sn*(sn+1)/2 < k) {
            sn++;
        }
        sn--;
        k = k-sn*(sn+1)/2;
        k %= n;
        if (k == 0)
            k = n;
        printf("%d\n", id[k-1]);
    }
    return 0;
}
