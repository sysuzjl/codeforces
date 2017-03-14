#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int b, c, a;
int counti[200010], maxs, iindex, counts, maxx;
map<int, int> mapS;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (mapS.find(a) != mapS.end())
            mapS[a]++;
        else
            mapS[a] = 1;
    }
    scanf("%d", &m);
    maxs = 0;
    maxx = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b);
        if (mapS.find(b) != mapS.end()) {
            counti[i] = mapS[b];
        } else {
            counti[i] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b);
        if (mapS.find(b) != mapS.end()) {
            counts = mapS[b];
        } else {
            counts = 0;
        }
        if (counti[i] > maxs) {
            maxs = max(counti[i], maxs);
            iindex = i;
            maxx = counts;
        } else if (counti[i] == maxs && counts > maxx) {
            iindex = i;
            maxx = counts;
        }
    }
    printf("%d\n", iindex+1);
}
