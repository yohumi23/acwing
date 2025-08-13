//
// Created by LoadingV on 2025/8/13.
//
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int N = 10010;
int in_degree[N];
//邻接表
int h[N], ne[N], e[N], idx = 0;

/**
 *
*
h[a] 记录顶点 a 的第一条边的下标（head）

e[idx] 存这条边的终点

ne[idx] 存这条边的下一条边的下标（next edge）

idx 是当前可用的边编号（全局递增）
 */
void link(int a, int b) {
    e[idx] = b;      // 1. 将边指向的节点b存入e[idx]
    ne[idx] = h[a];  // 2. 将当前边的下一条边指向原来a的头节点
    h[a] = idx++;    // 3. 更新a的头节点为当前边，并递增idx
    in_degree[b]++;
}
int n, m, a, b;

void topical() {
    queue<int> q;
    int res[N], res_idx = 0;
    for (int i = 1; i <= n; i++) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int head = q.front();
        res[res_idx++] = head;
        q.pop();
        for (int i = h[head]; i != -1; i = ne[i]) {
            int neighbor = e[i];
            in_degree[neighbor]--;
            if (!in_degree[neighbor]) {
                q.push(neighbor);
            }
        }
    }
    if (res_idx < n) {
        printf("-1\n");
    }else {
        for (int i = 0; i < res_idx; i++) {
            printf("%d ", res[i]);
        }
        puts("");
    }
}
int main() {
    memset(h, -1, sizeof h);
    memset(in_degree, 0, sizeof in_degree);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        link(a, b);
    }
    topical();


    return 0;
}