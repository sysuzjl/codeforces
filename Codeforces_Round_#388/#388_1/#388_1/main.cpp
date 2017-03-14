#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int k = n/2;
    printf("%d\n", k);
    for (int i = 0; i < k-1; i++) {
        printf("2 ");
    }
    if (n % 2 != 0)
        printf("3\n");
    else
        printf("2\n");
    return 0;
}