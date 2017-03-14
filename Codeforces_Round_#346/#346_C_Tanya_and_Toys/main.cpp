#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace  std;
map<int, int> hasType;
int a[100010];
int main() {
    int n, m, type;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &type);
        hasType[type] = 1;
    }
    int counti = 0;
    for (int i = 1; i <= 200010 && m >= 0; i++) {
        if (hasType.find(i) == hasType.end()) {
            m -= i;
            if (m >= 0)
                a[counti++] = i;
        }
    }
    printf("%d\n",  counti);
    for (int i = 0; i < counti; i++) {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}
