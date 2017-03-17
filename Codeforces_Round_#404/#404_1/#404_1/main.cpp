#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
map<string, int> mp;
int main() {
    int n;
    scanf("%d", &n);
    string s;
    mp.emplace("Tetrahedron", 4);
    mp.emplace("Cube", 6);
    mp.emplace("Octahedron", 8);
    mp.emplace("Dodecahedron", 12);
    mp.emplace("Icosahedron", 20);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ret += mp[s];
    }
    printf("%d\n", ret);
    return 0;
}