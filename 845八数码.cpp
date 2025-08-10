//
// Created by LoadingV on 2025/7/22.
//
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string target = "12345678x";
string source;
int d1[4] = {0, 0, -1, 1}, d2[4] = {1, -1, 0, 0};

bool in_bound(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

void bfs() {
    queue<string> q;
    unordered_map<string, int> step_map;
    step_map[source] = 0;
    q.push(source);
    while (q.size()) {
        string t = q.front();
        q.pop();
        int step = step_map[t];
        for (int i = 0; i < 4; i++) {
            int mov_x = d1[i], mov_y = d2[i];
            int idx = t.find('x');
            int new_x = idx / 3 + mov_x;
            int new_y = idx % 3 + mov_y;
            if (in_bound(new_x, new_y)) {
                swap(t[3 * new_x + new_y], t[idx]);
                if (!step_map.count(t)) {
                    step_map[t] = step + 1;
                    q.push(t);
                }
                swap(t[3 * new_x + new_y], t[idx]);
            }
        }
    }
    if (!step_map.count(target)) {
        printf("-1");
    }else {
        printf("%d\n", step_map[target]);
    }
}

int main() {
    char x;
    for (int i = 0; i < 9; i++) {
        cin >> x;
        source += x;
    }
    bfs();
    return 0;
}
