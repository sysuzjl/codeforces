#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    string result = s;
    int median = (n+1)/2-1;
    for (int i = 0; i < n; i++) {
        result[median] = s[i];
        if (n-1-median == median) {
            median--;
        } else if (n-1-median < median) {
            median = n-2-median;
        } else {
            median = n-1-median;
        }
    }
    cout << result << "\n";
    return 0;
}
