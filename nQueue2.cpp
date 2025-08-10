//   0 1 2
// 0   x
// 1   y x
// 2 y

#include<iostream>
using namespace std;
const int N = 10;
int n;

bool y[N], d1[N * 2], d2[N * 2];
char map[N][N];

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = '.';
        }
    }
}

void nQueue(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (!y[i] && !d1[idx + i] && !d2[idx - i + n]) {
            y[i] = true;
            d1[idx + i] = true;
            d2[idx - i + n] = true;
            map[idx][i] = 'Q';
            nQueue(idx + 1);
            y[i] = false;
            d1[idx + i] = false;
            d2[idx - i + n] = false;
            map[idx][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    init();
    nQueue(0);
    return 0;
}
