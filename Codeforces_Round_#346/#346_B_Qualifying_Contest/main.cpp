#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace  std;
struct T {
    int score;
    int i;
    string name;
    friend bool operator< (T a, T b) {
        if (a.i < b.i)
            return true;
        else if (a.i == b.i && a.score < b.score)
            return true;
        else
            return false;
    }
};
T a[100010];
int counti[10010];
int main() {
    int n, m;
    memset(counti, 0, sizeof(counti));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin>>a[i].name;
        cin>>a[i].i;
        cin>>a[i].score;
        counti[a[i].i]++;
    }
    sort(a, a+n);
    for (int j = 1; j <= m; j++) {
        int countc = counti[j];
        if (j!=0)
            counti[j] += counti[j-1];
        if (countc > 2 && a[counti[j]-2].score == a[counti[j]-3].score) {
            printf("?\n");
            continue;
        } else {
            cout << a[counti[j]-1].name << " " << a[counti[j]-2].name << "\n";
        }
    }
    return 0;
}
