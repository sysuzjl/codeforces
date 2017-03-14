#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
string sstr;
int main() {
    cin >> sstr;
    int len = sstr.length();
    int pos, pos_dot = 0;
    for (int i = 0; i < len; i++) {
        if (sstr[i] == '.')
            pos_dot = i;
        if (sstr[i] == 'e') {
            pos = i;
            break;
        }
    }
    string b = sstr.substr(pos+1);
    int interge = 0;
    for (int i = 0; i < b.length(); i++) {
        interge = interge * 10 + (b[i]-'0');
    }
    if (interge == 0) {
        if (pos-pos_dot == 2 && sstr[pos_dot+1] == '0')
            printf("%c\n", sstr[0]);
        else {
            for (int i = 0; i < pos; i++) {
                printf("%c", sstr[i]);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < pos_dot; i++) {
            printf("%c", sstr[i]);
        }
        int i = 0;
        while (i < interge) {
            if (pos_dot+1 != pos)
                printf("%c", sstr[++pos_dot]);
            else
                printf("0");
            i++;
        }
        if (pos_dot+1 != pos) {
            printf(".");
            while (pos_dot+1 != pos) {
                printf("%c", sstr[++pos_dot]);
            }
        }
        printf("\n");
    }
    return 0;
}
