#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char map[9][10];
int visb[8];
int visa[8];
int mina = 9, minb = 9;
int main() {
    int n = 8;
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }
    memset(visa, 0, sizeof(visa));
    memset(visb, 0, sizeof(visb));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'W') {
                if (!visb[j]) {
                    mina = min(mina, i);
                }
            } else if (map[i][j] == 'B') {
                visb[j] = 1;
            }
        
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (map[i][j] == 'B') {
                if (!visa[j]) {
                    minb = min(minb, 7 - i);
                }
            } else if (map[i][j] == 'W') {
                visa[j] = 1;
            }
            
        }
    }
    if (mina > minb) {
        printf("B\n");
    } else {
        printf("A\n");
    }
    return 0;
}
