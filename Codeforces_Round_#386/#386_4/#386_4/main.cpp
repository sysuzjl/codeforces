#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main() {
    int n, k, a, b;
    int flag = 1;
    string s;
    int first = 1, cnt_k = 0, cnt_a, cnt_b, maxB = 1;
    scanf("%d%d%d%d", &n ,&k, &a, &b);
    if (a % k != 0)
        cnt_a = a/k + 1;
    else
        cnt_a = a/k;
    if (b % k != 0)
        cnt_b = b/k + 1;
    else
        cnt_b = b/k;
    int mina = 0;
    if (cnt_a-1 > 0)
        mina = b/(cnt_a-1);
    else
        mina = b;
    if (cnt_a < cnt_b) {
        int t = cnt_a;
        cnt_a = cnt_b;
        cnt_b = t;
        maxB = 0;
        first = 0;
        if (cnt_a-1 > 0)
            mina = a/(cnt_a-1);
        else
            mina = a;
    }
    cnt_b = cnt_a-1;
    if (mina >= k) {
        if (maxB == 1 && (mina > k || mina*cnt_b < b)) {
            cnt_b = cnt_a;
            mina = b/cnt_b;
        } else if (maxB == 0 && (mina > k || mina*cnt_b < a)){
            cnt_b = cnt_a;
            mina = a/cnt_b;
        }
    }
    if (a < cnt_a-1 || b < cnt_a-1) {
        printf("NO\n");
    } else {
        for (int i = 0; i < n; ) {
            if (maxB == first) {
                if (first == 0) {
                    for (int j = 0; j < k && b > 0; j++) {
                        s += 'B';
                        b--;
                        i++;
                    }
                } else {
                    for (int j = 0; j < k && a > 0; j++) {
                        s += 'G';
                        a--;
                        i++;
                    }
                }
            } else {
                if (first == 0) {
                    if (cnt_b - cnt_k > 0) {
                        mina = max(b/(cnt_b-cnt_k), mina);
                    } else {
                        mina = b;
                    }
                    for (int j = 0; j < mina && b > 0; j++) {
                        s += 'B';
                        b--;
                        i++;
                    }
                } else {
                    if (cnt_b - cnt_k > 0) {
                        mina = max(a/(cnt_b-cnt_k), mina);
                    } else {
                        mina = a;
                    }
                    for (int j = 0; j < mina && a > 0; j++) {
                        s += 'G';
                        a--;
                        i++;
                    }
                }
                cnt_k++;
            }
            first = 1-first;
        }
        cout << s << endl;
    }
    
    return 0;
}
