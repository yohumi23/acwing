#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double n;
    scanf("%lf", &n);
    // ���� n ���������ú��ʵ�����
    double l = min(-1.0, n), r = max(1.0, n);
    // ѭ�� 100 ���Ա�֤�㹻�ľ���
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        double x = mid * mid * mid;
        if (x > n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    // ������
    printf("%lf\n", l);
    return 0;
}
