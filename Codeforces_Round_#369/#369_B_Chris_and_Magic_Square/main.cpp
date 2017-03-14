#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n, posX, posY;
long long a[505][505];
int main() {
    scanf("%d", &n);
    if (n== 1) {
        printf("1\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%I64d", &a[i][j]);
            if (a[i][j] == 0) {
                posX = i;
                posY = j;
            }
        }
    }
    long long res = 0, empSum = 0;
    int r = 0;
    //计算无空白数字一行的和
    if (posX == 0) {
        r = 1;
    }
    for (int i = 0; i < n; i++) {
        res += a[r][i];
        empSum += a[posX][i];
    }
    a[posX][posY] = res - empSum;
    if (a[posX][posY] <= 0) {
        printf("-1\n");
        return 0;
    }
    long long culSum = 0, rowSum = 0, ldiaSum = 0, rdiaSum = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        culSum = 0;
        rowSum = 0;
        for (int j = 0; j < n; j++) {
            culSum += a[j][i];
            rowSum += a[i][j];
        }
        if (culSum != res || rowSum != res) {
            flag = 1;
        }
        ldiaSum += a[i][i];
        rdiaSum += a[i][n-i-1];
    }
    if (ldiaSum != res || rdiaSum != res) {
        flag = 1;
    }
    if (flag) {
        printf("-1\n");
    } else {
        printf("%I64d\n", a[posX][posY]);
    }
    
    return 0;
}
