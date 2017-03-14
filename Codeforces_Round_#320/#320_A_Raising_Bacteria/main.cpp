#include  <cstdio>

int main() {
    int x;
    int c=0;
    scanf("%d", &x);
    while (x) {
        if (x & 1) {
            c++;
        }
        x >>= 1;
    }
    printf("%d\n", c);
}

