#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point {
    long long x;
    long long y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
}a[100010];
typedef Point Vector;
Vector operator+ (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y);}
Vector operator- (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y);}
Vector operator* (Vector A, long long p) { return Vector(A.x*p, A.y*p);}
Vector operator/ (Vector A, long long p) { return Vector(A.x/p, A.y/p);}
bool operator< (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
const long long eps = 1e-10;
long long Dot(Vector A, Vector B) {
    return A.x*B.x + A.y*B.y;
}
long long cross(Vector A, Vector B) {
    return A.x*B.y - A.y*B.x;
}
bool OnSegment(Point p, Point a1, Point a2) {
    if (cross(a1-p, a2-p) == 0 && Dot(a1-p, a2-p) < 0)
        return true;
    return false;
}
long long Area2(Point A, Point B, Point C) {
    return cross(B-A, C-A);
}
int main() {
    int n;
    int A, B, C;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    A = 1;
    B = 2;
    for (int i = 3; i <= n; i++) {
        if (OnSegment(a[i], a[A], a[B])) {
            B = i;
        } else if (cross(a[A]-a[i], a[B]-a[i]) == 0) {
            continue;
        } else {
            C = i;
            break;
        }
    }
    for (int i = C; i <= n; i++) {
        if (OnSegment(a[i], a[A], a[B])) {
            B = i;
        }
        if (cross(a[A]-a[i], a[B]-a[i]) != 0) {
            long long d1 = Area2(a[i], a[A], a[B]);
            long long d2 = Area2(a[C], a[A], a[B]);
            if (d1 < 0)
                d1 = -d1;
            if (d2 < 0)
                d2 = -d2;
            if (d1 < d2)
                C = i;
        }
    }
    printf("%d %d %d\n", A, B, C);
    return 0;
}
