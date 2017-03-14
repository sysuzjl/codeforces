#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
#define rep(i, l, n) for (int i = l; i < n; i++)
string s, a;
int d;
int main() {
    cin >> d >> a >> s;
    int flag = 1;
    if (s[0] == 'w')
        flag = 0;
    if (flag) {
        if (d <= 29)
            printf("12\n");
        else if (d <= 30)
            printf("11\n");
        else
            printf("7\n");
    } else {
        if (d == 5 || d==6)
            printf("53\n");
        else
            printf("52\n");
    }
    return 0;
}
