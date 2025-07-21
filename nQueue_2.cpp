//
// Created by LoadingV on 2025/7/21.
//


#include<iostream>
using namespace std;

int n;
const int N = 10;

bool row[N], col[N], d1[2 * N], d2[2 * N];
char map[N][N];

void dfs(int x, int y, int s) {
    if (y == n) x++, y = 0;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i++) puts(map[i]);
            puts("");
        }
        return;
    }
    dfs(x, y + 1, s);
    if (!row[x] && !col[y] && !d1[n - x + y] && !d2[x + y]) {
        row[x] = col[y] = d1[n - x + y] = d2[x + y] = true;
        map[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = d1[n - x + y] = d2[x + y] = false;
        map[x][y] = '.';
    }
}
// 时间复杂度是 2 ^ ( n ^ 2)  时间复杂度略差

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}
