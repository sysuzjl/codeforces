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
int n, p, m;
int b[500010];
int leftt[500010], rightt[500010];
int ll = 0;
stack<int> q;
string barkets, op;
int main() {
    scanf("%d%d%d", &n, &m, &p);
    p--;
    cin>>barkets;
    cin>>op;
    for (int i = 0; i < n; i++) {
        leftt[i] = i-1;
        rightt[i] = i+1;
        if (barkets[i] == '(')
            q.push(i);
        else {
            b[q.top()] = i;
            b[i] = q.top();
            q.pop();
        }
    }
    rightt[n-1] = -1;
    for (int i = 0; i < m; i++) {
        if (op[i] == 'L') {
            if (leftt[p] != -1)
                p = leftt[p];
        }
        else if (op[i] == 'R') {
            if (rightt[p] != -1)
                p = rightt[p];

        }
        else {
            int lf = p;
            int rt = b[p];
            if (lf > rt)
                swap(lf, rt);
            if (rightt[rt] != -1)
                p = rightt[rt];
            else
                p = leftt[lf];
            leftt[rightt[rt]] = leftt[lf];
            rightt[leftt[lf]] = rightt[rt];
            if (lf == ll)
                ll =rightt[rt];
        }
    }
    string c;
    for (int i = ll; i != -1; i = rightt[i]) {
        c += barkets[i];
    }
    cout << c << endl;
    return 0;
}
