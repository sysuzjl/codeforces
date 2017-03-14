#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int d[100010], n;
int visit[100010];
string str;
int main() {
    scanf("%d", &n);
    memset(visit, 0,sizeof(visit));
    cin>>str;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &d[i]);
    }
    int first = 1;
    while (first > 0 && first <= n) {
        if (visit[first-1]) {
            printf("INFINITE\n");
            return 0;
        }
        visit[first-1] = 1;
        if (str[first-1] == '>') {
            first += d[first];
        } else {
            first -= d[first];
        }
    }
    printf("FINITE\n");
    return 0;
}
