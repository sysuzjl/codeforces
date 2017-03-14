#include <iostream>
#include <cstdio>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d", &n);
    if (n % 2 != 0)
        printf("0\n");
    else
        printf("%d\n", (n-1)/4);
    return 0;
}
