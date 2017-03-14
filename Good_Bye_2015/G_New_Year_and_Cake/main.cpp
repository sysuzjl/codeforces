#include <cstdio>
const int module = 1e9 + 7;
const int maxn = 1000010;
int n;
long long add[maxn], addi[maxn], sum_product;
long long sum_x, sum_y;
struct Point {
    int x;
    int y;
    long long operator*(Point & a) {
        return -a.x*1LL*y+x*1LL*a.y;
    }
}point[maxn];
int main() {
    long long ans = 0, tot = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &point[i].x, &point[i].y);
        if (i != 0) {
            add[i] = point[i]*point[i-1];
            addi[i] = (addi[i-1] + point[i]*point[i-1]%module*i%module + module) %module;
            tot = tot + add[i];
        }
    }
    tot += point[0]*point[n-1];
    point[n].x = point[0].x;
    point[n].y = point[0].y;
    for (int i = n; i <= 2 * n; i++) {
        point[i].x = point[i-n].x;
        point[i].y = point[i-n].y;
        add[i] = point[i]*point[i-1];
        addi[i] = (addi[i-1] + point[i]*point[i-1]%module*i%module + module) % module;
    }
    int b = 0;
    Point P;
    for (int i = 0; i < n; i++) {
        while (true) {
            unsigned long long tmp = 2 *((unsigned long long) sum_product + add[b] +(unsigned long long)(point[i]*point[b]));
            if (tmp < tot || (tmp == tot && b < n)) {
                sum_x = (sum_x + point[b].x)% module;
                sum_y = (sum_y + point[b].y)% module;
                sum_product += add[b];
                b++;
            } else {
                break;
            }
        }
        long long temp = (sum_product% module * b % module - (addi[b-1] - addi[i]) % module) % module;
        P.x = sum_x % module;
        P.y = sum_y % module;
        temp = (temp + point[i] * P % module + module) % module;
        ans = (ans + temp) % module;
        sum_x -= point[i].x;
        sum_y -= point[i].y;
        sum_product -= add[i+1];
    }
    printf("%lld\n", (((tot%module*((n*1LL*(n-3)/2)%module))-2 * ans)%module+module)%module);
    return 0;
}
