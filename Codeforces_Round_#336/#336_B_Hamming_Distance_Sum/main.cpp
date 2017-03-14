#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string a, b;
int nums[200010];
int main() {
    cin>> a >> b;
    int len = a.length();
    int len2 = b.length();
    memset(nums, 0, sizeof(nums));
    nums[len2] = 0;
    for (int i = len2-1; i >= 0; i--) {
        if (b[i] == '1') {
            if (i == len2-1)
                nums[i]++;
            else
                nums[i] = nums[i+1]+1;
        } else {
            nums[i] = nums[i+1];
        }
    }
    long long sum = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '0') {
            sum += nums[i] - nums[len2-len+i+1];
        } else {
            sum += (len2-len+1) - nums[i] + nums[len2-len+i+1];
        }
    }
    printf("%lld\n", sum);
    return 0;
}
