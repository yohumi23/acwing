#include<iostream>
using namespace std;
const int N = 1010;
int q[N][N], s[N][N];
int n,m,p;

int main(){
    int t;
    int x1, y1, x2, y2;
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &q[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + q[i][j]; 
        }
    }
    while(p--){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int res = s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
        cout << res << endl;
    }
    
}

