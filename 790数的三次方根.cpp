#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double n;
    scanf("%lf", &n);
    // 根据 n 的正负设置合适的区间
    double l = min(-1.0, n), r = max(1.0, n);
    // 循环 100 次以保证足够的精度
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        double x = mid * mid * mid;
        if (x > n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    // 输出结果
    printf("%lf\n", l);
    return 0;
}
