#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int columnl[100004];
int columnr[100004];
int main() {
    int n;
    int minl = 700, maxl = -700, indexl = -1, indexr = -1;
    scanf("%d", &n);
    int suml = 0, sumr = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%du", &columnl[i], &columnr[i]);
        suml += columnl[i];
        sumr += columnr[i];
        if (minl > columnl[i]-columnr[i]) {
            minl = min(minl, columnl[i]-columnr[i]);
            indexl = i;
        }
        if (maxl < columnl[i]-columnr[i]) {
            maxl = max(maxl, columnl[i]-columnr[i]);
            indexr = i;
        }
    }
    int index = -1;
    int beauty = abs(suml-sumr);
    if (abs(suml-sumr) < abs(suml-sumr+2*columnr[indexl]-2*columnl[indexl])) {
        index = indexl;
        beauty = abs(suml-sumr+2*columnr[indexl]-2*columnl[indexl]);
    }
    if (beauty < abs(suml-sumr+2*columnr[indexr]-2*columnl[indexr])) {
        index = indexr;
        beauty = abs(suml-sumr+2*columnr[indexr]-2*columnl[indexr]);
    }
    printf("%d\n",index+1);
    return 0;
}