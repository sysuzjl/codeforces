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
int n, maxd, mind, flag, flag1;
int main() {
    scanf("%d", &n);
    flag = 0;
    if (n % 7 >= 2)
        flag = 2;
    else
        flag = n%7;
    if (n % 7 == 6)
        flag1 = 1;
    else
        flag1 = 0;
    maxd = n/7*2+flag;
    mind = n/7*2+flag1;
    printf("%d %d\n", mind, maxd);
    return 0;
}
