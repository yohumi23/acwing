//
// Created by LoadingV on 2025/8/10.
//
#include <iostream>
#include <queue>
#include <cstring>

/**
 *
 *1.考虑越界问题
 *2.设置已被访问的时机，其实第一次被找到就说明最短了，具体自己思考一下就理解了,
 *这时候入队的同时就可以设置为被访问到了，后面的访问也会比比它更早更快了
 */
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
int mp[N][N];

int n, m;
int dis[N][N];
bool vis[N][N];
int d1[4] = {0, -1, 0, 1}, d2[4] = {1, 0, -1, 0};

bool in_bound(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs() {
    queue<PII> q;
    q.push({1, 1});
    dis[1][1] = 0;
    while (q.size()) {
        auto current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = d1[i] + current.first;
            int new_y = d2[i] + current.second;
            if (in_bound(new_x, new_y) && !mp[new_x][new_y] && !vis[new_x][new_y]) {
                dis[new_x][new_y] = dis[current.first][current.second] + 1;
                q.push({new_x, new_y});
                vis[new_x][new_y] = true;
            }
        }

    }
    printf("%d\n", dis[n][m]);
}



int main() {
    cin >> n >> m;
    memset(dis, 0x4f, sizeof dis);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    bfs();
    return 0;
}
