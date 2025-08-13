#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;


/**
 * 1.将所有边按照权重从小到大排序 o(mlogm)
 * 2.枚举每条边a -- c --> b
 *      if a.b 不联通
 *          将这条边加入集合中
 *
 * # 需要并查集
 * @return
 */

int p[N];
int n, m;

struct E {
    int a, b, w;

    bool operator<(const E &e) {
        return this->w < e.w;
    }
} edges[N * 2];

int in_tree = 0;
int total_weight = 0;


int find_ancestor(int a) {
    if (a != p[a]) p[a] = find_ancestor(p[a]);
    return p[a];
}

void kruskal() {
    for (int i = 0; i < m; i++) {
        auto e = edges[i];
        int vector_a = e.a;
        int vector_b = e.b;
        int weight = e.w;
        int p_a = find_ancestor(vector_a);
        int p_b = find_ancestor(vector_b);
        if (p_a != p_b) {
            in_tree++;
            total_weight += weight;
            p[p_a] = p_b;
        }
    }
    if (in_tree < n - 1) {
        printf("impossible\n");
    } else {
        printf("%d\n", total_weight);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m);
    kruskal();

    return 0;
}
