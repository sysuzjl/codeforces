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
#include <queue>
#include <stack>
using namespace std;
int cnt[13];
string s;
string remaind, tt;
int len, ll;
int main() {
    cin>> s;
    cin>>tt;
    int len = s.length();
    int n = 0;
    ll = 0;
    if (len == 2) {
        cout << tt << endl;
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        cnt[s[i]-'0']++;
    }
    int t = len-1;
    int digits = 1;
    int dt;
    int f = t;
    dt = 0;
    while (f > 0) {
        f/=10;
        dt++;
    }
    while (t+dt != len) {
        digits++;
        t = len-digits;
        int f = t;
        dt = 0;
        while (f > 0) {
            f/=10;
            dt++;
        }
    }
    len = t;
    while (t) {
        cnt[t%10]--;
        t /= 10;
    }
    int firstt = tt[0]-'0', flag = 0, mintt = 1;
    for (int i = 0; i < tt.length(); i++) {
        cnt[tt[i]-'0']--;
        if (i != 0 && !flag) {
            if (tt[i]-'0' < firstt) {
                flag = 1;
                mintt = tt[i]-'0';
            } else if (tt[i]-'0' > firstt)
                flag = 2;
        }
    }
    int countzero = 0;
    if (mintt == 0) {
        int flagg = 0;
        for (int i = 0; i < tt.length(); i++) {
            if (tt[i] == '0') {
                flagg = 1;
                countzero++;
            } else if (flagg == 1) {
                flag = 3;
                break;
            }
        }
        if (flag == 3 && countzero > cnt[0])
            flag = 1;
    }
    for (int i = 1; i < 10; i++) {
        if (cnt[i] > 0) {
            ll = i;
            break;
        }
    }
    string result;
    if (firstt != 0 && ll != 0) {
        if (ll < firstt) {
            result += (char)(ll+'0');
            cnt[ll]--;
            for (int i = 0; i < firstt; i++) {
                while (cnt[i] > 0) {
                    result += (char)(i+'0');
                    cnt[i]--;
                }
                ll = i+1;
            }
        }
        else if (ll == firstt && cnt[0] > 0 && (mintt != 0 || flag != 1)) {
            result += (char)(ll+'0');
            cnt[ll]--;
            while (cnt[0] > 0) {
                result += '0';
                cnt[0]--;
            }
        }
        if (ll == firstt && flag != 1 && flag != 3) {
            while (cnt[ll] > 0) {
                result += (char)(ll+'0');
                cnt[ll]--;
            }
            ll = ll+1;
        }
    } else if (ll != 0){
        result += (char)(ll+'0');
        cnt[ll]--;
        while (cnt[0] > 0) {
            result += '0';
            cnt[0]--;
        }
    }
    result += tt;
    for (int i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
            result += (char)(i+'0');
            cnt[i]--;
        }
    }
    cout << result << endl;
    return 0;
}
