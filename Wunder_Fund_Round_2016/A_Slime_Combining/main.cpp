#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int t = n;
    int c = 0;
    while (t > 1) {
        t /= 2;
        c++;
    }
    printf("%d", c+1);
    n -= (1<<c);
    t = n;
    while (n) {
        c = 0;
        while (t > 1) {
            t /= 2;
            c++;
        }
        printf(" %d", c+1);
        n -= (1<<c);
        t = n;
    }
    printf("\n");
    return 0;
}
