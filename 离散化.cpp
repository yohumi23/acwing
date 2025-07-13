#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * 
离散化三部曲：
1. 坐标收集全，操作查询都得算；
2. sort + unique 做去重，原始大小变编号；
3. 建表映射坐标序，数组结构就能用。
*/
int main() {
    int n, m;
    cin >> n >> m;
    // x 就是x轴上的坐标
    map<int, long long> add; // x -> c ，所有坐标为x的累加值就是放在map->v上了
    vector<int> coords; // 原始坐标列表（含查询和修改点）

    // 读入 n 次操作
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        add[x] += c;
        coords.push_back(x);
    }

    // 读入 m 次查询，同时记录左右端点用于离散化
    vector<pair<int, int>> queries;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l, r);
        coords.push_back(l); // 查询 l
        coords.push_back(r); // 查询 r
    }

    // 离散化
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    int N = coords.size();

    map<int, int> index; // 坐标 → 编号（下标）
    for (int i = 0; i < N; ++i) {
        // 离散下标（从1开始）
        index[coords[i]] = i + 1;
    }

    // 构建前缀和数组, 前缀和就是 默认从1开始的
    vector<long long> pre(N + 2, 0);
    for (const auto& [x, c] : add) {
        int idx = index[x];
        pre[idx] += c;
    }

    // 前缀和计算
    for (int i = 1; i <= N; ++i) {
        pre[i] += pre[i - 1];
    }

    // 处理查询
    for (const auto& [l, r] : queries) {
        // 找离散化下标 lower_bound >= l 的index, upper_bound > r 的index
        int l_idx = lower_bound(coords.begin(), coords.end(), l) - coords.begin() + 1; // 因为index从1开始
        int r_idx = upper_bound(coords.begin(), coords.end(), r) - coords.begin();  // 不用+1

        if (r_idx < l_idx) {
            cout << 0 << endl;
        } else {
            cout << pre[r_idx] - pre[l_idx - 1] << endl;
        }
    }

    return 0;
}
