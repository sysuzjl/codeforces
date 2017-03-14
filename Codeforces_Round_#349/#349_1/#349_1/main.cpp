#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
string s;
set <string> a;
int len;
int bb[10010];
int main() {
    int len;
    cin >> s;
    len = s.length();
    int t = 2, flag;
    int count = 0;
    bb[len] = 1;
    while (len >= t + 5) {
        string b = s.substr(len-t, 2);
        string c;
        if (len-t+4 <= len && bb[len-t+2] == 1)
            c = s.substr(len-t+2, 2);
        if (b != c) {
            if (bb[len-t+2] == 1) {
                a.insert(b);
                bb[len-t] = 1;
            }
        }
        b = s.substr(len-t, 3);
        if (len-t+6 <= len && bb[len-t+3] == 1)
            c = s.substr(len-t+3, 3);
        if (b!=c) {
            if (bb[len-t+3] == 1) {
                a.insert(b);
                bb[len-t] = 1;
            }
        }
        t++;
    }
    count = a.size();
    printf("%d\n", count);
    for (set<string>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}