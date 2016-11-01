#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct rectangular {
    int h;
    int l;
    int w;
    int index;
}volumn[100004];
bool cmp(rectangular a, rectangular b) {
    if (a.w < b.w)
        return true;
    else if(a.w == b.w && a.l < b.l)
        return true;
    else if (a.w == b.w && a.l == b.l && a.h < b.h)
        return true;
    else
        return false;
}
int main() {
    int n;
    int a[3];
    scanf("%d", &n);
    double maxr = 0;
    int maxi1 = -1, maxi2 = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        sort(a, a+3);
        volumn[i].h = a[0];
        volumn[i].l = a[1];
        volumn[i].w = a[2];
        volumn[i].index = i;
        if (maxr < volumn[i].h/2.0) {
            maxr = volumn[i].h/2.0;
            maxi1 = i;
        }
    }
    sort(volumn, volumn+n, cmp);
    for (int i = 1; i < n; i++) {
        if (volumn[i].l == volumn[i-1].l && volumn[i].w == volumn[i-1].w) {
            if (maxr < min(volumn[i].h+volumn[i-1].h, volumn[i-1].w)/2.0) {
                maxr = min(volumn[i].h+volumn[i-1].h, volumn[i-1].w)/2.0;
                maxi1 = volumn[i].index;
                maxi2 = volumn[i-1].index;
            }
        }
    }
    if (maxi2 == -1) {
        printf("1\n");
        printf("%d\n", maxi1+1);
    } else {
        printf("2\n");
        printf("%d %d\n", maxi1+1, maxi2+1);
    }
    return 0;
}