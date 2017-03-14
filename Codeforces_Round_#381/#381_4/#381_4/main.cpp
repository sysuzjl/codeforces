#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
    int start;
    int end;
    int v;
    int next;
}e[200004];
int heads[200004];
int node[200004];
int cnt[200004];
int n;
int deepfirst(int v, int sum) {
    for (int i = heads[v]; i != -1; i = e[i].next) {
        int sum = 0;
        sum += deepfirst(e[i].next);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i]);
        heads[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        int pi, wi;
        scanf("%d%d", &pi, &wi);
        e[i].start = i+1;
        e[i].end = pi;
        e[i].v = wi;
        e[i].next = heads[pi];
        heads[pi] = i;
    }
    deepfirst(1);
    return 0;
}