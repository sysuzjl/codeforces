#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>
#include <ctime>
using namespace std;
int main() {
    int n;
    string s;
    scanf("%d", &n);
    n = 200000;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 200000; i++) {
        int d =rand() % 2;
        if (d == 1)
           s += 'D';
        else
            s += 'R';
    }
    int cntN = n;
    int cntF = 0, cntS = 0;
    char c = s[0];
    int flag = 1;
    while (cntN != 1) {
        n = cntN;
        cntN = 0;
        for (int i = 0; i < n; i++) {
            if (c == s[i]) {
                cntF++;
                s[cntN++] = s[i];
            } else if (cntF > 0)
                cntF--;
            else {
                if (c == 'D')
                    c = 'R';
                else
                    c = 'D';
                s[cntN++] = s[i];
                cntF = 1;
            }
        }
        flag = 1;
        for (int i = 0; i < cntN; i++) {
            if (s[i] != s[0])
                flag = 0;
        }
        if (flag) {
            break;
        }
    }
    printf("%c\n", s[0]);
    return 0;
}