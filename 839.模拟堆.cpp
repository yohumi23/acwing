#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], kh[N], hk[N];

int query, sz = 0;

void swap_heap(int i, int j) {
    swap(kh[hk[i]], kh[hk[j]]);
    swap(hk[i], hk[j]);
    swap(h[i], h[j]);
}


void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) {
        swap_heap(u, u / 2);
        u /= 2;
    }
}

void down(int i) {
    int min_idx = i;
    int l = i * 2, r = i * 2 + 1;
    if (l <= sz && h[l] < h[min_idx]) min_idx = l;
    if (r <= sz && h[r] < h[min_idx]) min_idx = r;
    if (min_idx != i) {
        swap_heap(min_idx, i);
        down(min_idx);
    }
}

int main() {
    scanf("%d", &query);
    int k, x;
    string opt;
    int m = 0;
    while (query--) {
        cin >> opt;
        if (opt == "I") {
            cin >> x;
            m++;
            sz++;
            h[sz] = x;
            kh[m] = sz, hk[sz] = m;
            up(sz);
        } else if (opt == "PM") {
            cout << h[1] << endl;
        } else if (opt == "DM") {
            // h[1] = h[sz]; 不能这么弄
            swap_heap(1, sz);
            sz--;
            down(1);
        } else if (opt == "D") {
            cin >> k;
            k = kh[k];
            // h[k] = h[sz];
            swap_heap(k, sz);
            sz--;
            up(k), down(k);
        } else if (opt == "C") {
            cin >> k >> x;
            k = kh[k];
            h[k] = x;
            up(k), down(k);
        }
    }

    return 0;
}
