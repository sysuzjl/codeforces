#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int a[504];
int b[504];
int btoa[504];
int maxa[504];
int indexa[504];
int main() {
    int an, bn;
    int t = 0, suma, sumb, sum;
    scanf("%d", &an);
    for (int i = 0; i < an; i++) {
        scanf("%d", &a[i]);
        suma += a[i];
    }
    scanf("%d", &bn);
    for (int i = 0; i < bn; i++) {
        scanf("%d", &b[i]);
        maxa[i] = -1;
        sumb += b[i];
    }
    if (suma != sumb) {
        printf("NO\n");
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < bn; i++) {
        sum = 0;
        for (int j = t; j < an; j++) {
            sum += a[j];
            if (maxa[cnt] < a[j]) {
                maxa[cnt] = a[j];
                indexa[cnt] = j;
            }
            if (sum == b[i]) {
                btoa[cnt++] = j;
                t = j+1;
                break;
            }
        }
        if (sum > b[i] || sum < b[i]) {
            printf("NO\n");
            return 0;
        }
    }
    int flag = 0, mina;
    t = 0;
    for (int i = 0; i < bn; i++) {
        flag = 0;
        for (int j = t; j <= btoa[i]; j++) {
            if (maxa[i] != a[j] ||(i == 0 && btoa[i] == 0)|| btoa[i] - btoa[i-1] == 1) {
                flag = 1;
                break;
            }
        }
        t = btoa[i]+1;
        if (!flag) {
            break;
        }
    }
    if (!flag) {
        printf("NO\n");
    } else {
        t = 0;
        printf("YES\n");
        for (int i = 0; i < bn; i++) {
            int maxI = indexa[i];
            int tmp = maxI;
            int gap = -1;
            if (i != 0)
                gap = btoa[i-1];
            while (maxI > t) {
                printf("%d L\n", i+maxI-gap);
                a[maxI-1] += a[maxI];
                maxI--;
            }
            a[tmp] = a[maxI];
            if (tmp < btoa[i] && a[tmp] == a[tmp+1]) {
                int k = tmp;
                while (a[k] == a[k+1]) {
                    k++;
                }
                int ks = k;
                while (k < btoa[i]) {
                    printf("%d R\n", i+ks-gap);
                    k++;
                }
                while (ks > t) {
                    printf("%d L\n", i+ks-gap);
                    ks--;
                }
                
            } else {
                while (tmp < btoa[i]) {
                    printf("%d R\n", i+1);
                    tmp++;
                }
            }
            t = btoa[i]+1;
        }
    }
    return 0;
}