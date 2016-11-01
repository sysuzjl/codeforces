#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    int len = s.length();
    int start = -1;
    int maxJ = -1;
    int p = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            maxJ = min(maxJ, i-start);
            start = i;
        }
    }
    maxJ = max(maxJ, len-start);
    printf("%d\n", maxJ);
    return 0;
}