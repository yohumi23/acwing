#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int q[N];

void heapify(int idx, int n){
    int min = idx;
    int l = idx * 2, r = l + 1;
    if(l <= n && q[l] < q[min]) min = l;
    if(r <= n && q[r] < q[min]) min = r;
    if(min != idx){
        swap(q[min], q[idx]);
        heapify(min, n);
    }
}

// 建立一个小跟堆
void build(){
    for(int i = n / 2; i >= 1; i--){
        heapify(i, n);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &q[i]);
    }
    build();
    for(int i = n; i > n - m ; i--){
        swap(q[1], q[i]);
        heapify(1, i - 1);
    }
    for(int i = n; i > n - m; i--){
        cout << q[i] << " ";
    }
    cout << endl;


    return 0;
}