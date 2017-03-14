#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    int t, x, s;
    scanf("%d%d%d", &t, &s, &x);
    if (x < t) {
        printf("NO\n");
    } else {
        int interval = x-t;
        if (interval % s == 0 || (interval % s == 1 && x != t+1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
