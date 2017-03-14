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
int n;
long long k;
int a[100010];
int b[100010];
struct nums {
    int sum;
    int remaind;
    int a;
    friend bool operator<(nums a, nums b) {
        return a.sum < b.sum;
    }
} s[100010];
int main() {
    scanf("%d%lld", &n, &k);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        s[i].sum = b[i]/a[i];
        s[i].remaind = b[i] % a[i];
        s[i].a = a[i];
    }
    sort(s, s+n);
    int countt = 0;
    int index;
    long long remaind, re = 0, temp;
    for (int i = 0; i < n; i++) {
        index = i;
        remaind = s[i].remaind;
        s[i].remaind = 0;
        re+=s[i].a;
        while (i+1 < n && s[i].sum == s[i+1].sum) {
            i++;
            remaind += s[i].remaind;
            s[i].remaind = 0;
            re+=s[i].a;
        }
        k = k - (re-remaind);
        if (k < 0) {
            printf("%d\n", s[i].sum);
            return 0;
        }
        if (i+1 < n) {
            countt = s[i+1].sum - s[i].sum-1;
            if (countt != 0) {
                temp = k - (re*countt);
                if (temp > 0) {
                    k = temp;
                    continue;
                } else {
                    int flag = k/re;
                    printf("%d\n", s[i].sum+1+flag);
                    return 0;
                }
            }
        } else {
            int flag = k/re;
            printf("%d\n", s[i].sum+1+flag);
            return 0;
        }
    }
    return 0;
}
