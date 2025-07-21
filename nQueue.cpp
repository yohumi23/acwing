//
// Created by LoadingV on 2025/7/21.
//
#include<iostream>
#include<cstring>
using namespace std;
int col[11], d1[100], d2[100];
char map[11][11];

int n;

// u是行号
void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        return;
    }
    // 遍历列, i = column_no
    for (int i = 0; i < n; i++) {
        if (!col[i]  && !d1[ u + i] && !d2[n - u + i]) {
            col[i] = d1[u + i] = d2[n - u +i] = 1;
            map[u][i] = 'Q';
            dfs(u + 1);
            col[i] = d1[u + i] = d2[n - u +i] = 0;
            map[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j]  = '.';
        }
    }
    dfs(0);

    return 0;
}
