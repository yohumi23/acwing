//
// Created by LoadingV on 2025/7/31.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 210;

int d[N][N];


void fff(int dot) {
    for (int k = 1; k <= dot; k++) {
        for (int i = 1; i <= dot; i++) {
            for (int j = 1; j <= dot; j++) {
                if (d[i][k] != 0x3f3f3f3f && d[k][j] != 0x3f3f3f3f) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int x, y, z;
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    while (m--) {
        cin >> x >> y >> z;
        //这里是重点！！
        d[x][y] = min(z, d[x][y]);
    }
    fff(n);
    while (k--) {
        cin >> x >> y;
        if (d[x][y] == 0x3f3f3f3f) {
            printf("impossible\n");
        } else {
            printf("%d\n", d[x][y]);
        }
    }
    return 0;
}
