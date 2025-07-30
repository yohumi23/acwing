//
// Created by LoadingV on 2025/7/30.
//
#include<iostream>
#include<cstring>
#include<queue>
const int INF = 0x3f3f3f3f;
using namespace std;
const int N = 100010;

typedef pair<int, int> PII;

int n, m, x, y, z;
PII e[N];
int ne[N], h[N], idx = 0, d[N], cnt[N];
bool in_queue[N];

void add(int a, int b, int w) {
    e[idx] = {b, w};
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        in_queue[i] = true;
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        in_queue[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            auto [near, w] = e[i];
            if (d[near] > d[t] + w) {
                d[near] = d[t] + w;
                if (!in_queue[near]) {
                    q.push(near);
                    in_queue[near] = true;
                    cnt[near] = cnt[t] + 1;
                    if (cnt[near] >= n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(d, 0x3f, sizeof d);
    memset(cnt, 0, sizeof cnt);
    while (m--) {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    bool exist = spfa();
    if (!exist) printf("No\n");
    else printf("Yes\n");
    return 0;
}
