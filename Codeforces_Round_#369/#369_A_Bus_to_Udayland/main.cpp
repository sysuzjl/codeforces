#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n, flag  = 0;
string str[1010];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        if (!flag) {
            if (str[i][0] == 'O' && str[i][1] == 'O') {
                str[i][0] = '+';
                str[i][1] = '+';
                flag = 1;
            } else if (str[i][3] == 'O' && str[i][4] == 'O') {
                str[i][3] = '+';
                str[i][4] = '+';
                flag = 1;
            }
        }
    }
    if (flag) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            cout << str[i] << endl;
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
