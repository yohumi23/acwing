//
// Created by LoadingV on 2025/7/22.
//


#include<iostream>
#include <string.h>
using namespace std;
const int N = 100;

typedef pair<int, int> PII;

int d[N][N], g[N][N];
int n, m;
PII q[N * N];

void bfs() {
    int hh = 0, tt = -1;
    q[++tt] = {0, 0};
    d[0][0] = 0;
    while (hh <= tt) {
        auto pos = q[hh++];
        int dx[4] = {0, -1, 1, 0}, dy[4] = {1, 0, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + pos.first, ny = dy[i] + pos.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] == -1 && !g[nx][ny]) {
                d[nx][ny] = d[pos.first][pos.second] + 1;
                q[++tt] = {nx, ny};
            }
        }
    }
}

int main() {
    memset(d, -1, sizeof d); // -1D = 0xFF

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    bfs();
    printf("%d", d[n-1][m-1]);
    return 0;
}
