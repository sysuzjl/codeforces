#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
char c[28];
int pre[28];
int main() {
    int n, m, t;
    char x, y;
    string s, s1 = "";
    scanf("%d%d", &n, &m);
    getline(cin, s);
    getline(cin, s);
    for (int i = 0; i < 26; i++) {
        c[i] = 'a'+ i;
    }
    for (int i = 0; i < 26; i++) {
        pre[i] = i;
    }
    for (int i = 0; i < m; i++) {
        x = getchar();
        y = getchar();
        y = getchar();
        c[pre[x-'a']] = y;
        c[pre[y-'a']] = x;
        t = pre[y-'a'];
        pre[y-'a'] = pre[x-'a'];
        pre[x-'a'] = t;
        y = getchar();
    }
    for (int i = 0; i < n; i++) {
        s1 += c[s[i]-'a'];
    }
    cout<<s1<<endl;
    return 0;
}
