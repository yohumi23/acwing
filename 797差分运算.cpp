#include<iostream>
using namespace std;
int n,m;
const int N = 1e5 + 10;
int a[N], b[N];//a是原数组，b是差分数组

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    //初始化差分数组
    for(int i = 1; i <= n; i++)
        insert(i, i, a[i]);
    while(m--){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
    }    
    for(int i = 1; i <=n; i++) b[i] += b[i-1];
    for(int i = 1; i <=n; i++) printf("%d ", b[i]);
    
    return 0;
}
