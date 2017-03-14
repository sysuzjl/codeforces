#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
int n, k;
string s;
int main() {
    scanf("%d%d", &n, &k);
    cin >> s;
    int len = s.length();
    string temp = s;
    int cnt = 1, maxcnt = 1, changesum = 0;
    int l = 0, r = 1;
    while (r < len) {
        if (s[r] == s[0]) {
            cnt++;
            r++;
            maxcnt = max(cnt, maxcnt);
        } else {
            if (changesum < k) {
                changesum++;
                cnt++;
                maxcnt = max(cnt, maxcnt);
                r++;
            }
            else {
                maxcnt = max(cnt, maxcnt);
                while (s[l] == s[0] && l < r) {
                    l++;
                    cnt--;
                }
                l++;
                cnt--;
                changesum--;
            }
        }
    }
    maxcnt = max(cnt, maxcnt);
    int i = 0, t;
    while (s[0] == s[i]) {
        i++;
    }
    t = i;
    cnt = 1, changesum = 0;
    l = t, r = t+1;
    if (k > 0) {
        changesum++;
        l = 0; r = 1;
    }
    while (r < len) {
        if (s[r] == s[t]) {
            cnt++;
            r++;
            maxcnt = max(cnt, maxcnt);
        } else {
            if (changesum < k) {
                changesum++;
                cnt++;
                maxcnt = max(cnt, maxcnt);
                r++;
            }
            else {
                maxcnt = max(cnt, maxcnt);
                while (s[l] == s[t] && l < r) {
                    l++;
                    cnt--;
                }
                l++;
                cnt--;
                changesum--;
            }
        }
    }
    maxcnt = max(cnt, maxcnt);
    printf("%d\n", maxcnt);
    return 0;
}