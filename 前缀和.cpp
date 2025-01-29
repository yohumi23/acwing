#include<iostream>
using namespace std;
const int N = 1e5+10;
int s[N];

int main(){
    int n, m;
    int t;
    int l, r;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        s[i] = s[i-1] + t;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", &l, &r);
        cout << s[r] - s[l-1] << endl;
    }
}
