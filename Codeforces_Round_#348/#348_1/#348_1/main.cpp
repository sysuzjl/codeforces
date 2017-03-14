#include <cstdio>
#include <map>
#include <queue>
using namespace std;
struct edge {
    int type;
    int t;
    friend bool operator< (edge a, edge b) {
        return a.t > b.t;
    }
};
int countn[1000010];
priority_queue<edge> qq[1000010];
map<int, int> p;
int n, len = 1;
int main() {
    int n;
    int a, t, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &t, &x);
        if (a == 1) {
            if (p.find(x) == p.end()) {
                p[x] = len;
                len++;
            }
            countn[p[x]]++;
            edge d;
            d.type = 1;
            d.t = t;
            qq[p[x]].push(d);
        } else if (a==2) {
            qq[p[x]].pop();
        } else {
            priority_queue<edge>::iterator it;
            
        }
    
    }
}