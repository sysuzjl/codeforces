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
#include <cmath>
using namespace std;
int main() {
    long long m, n;
    cin >> m >> n;
    if (n >= m)
        cout << m << endl;
    else {
        int res = ceil(sqrt(2.0*(m-n)));
        while (res*1LL*(res+1) >= 2*(m-n))
            res--;
        cout << n+res+1 << endl;
    }
    return 0;
}