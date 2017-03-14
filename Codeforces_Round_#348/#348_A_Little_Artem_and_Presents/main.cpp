#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    int flag = 0;
    if (n % 3 != 0)
        flag = 1;
    printf("%d", n/3*2 + flag);
}
