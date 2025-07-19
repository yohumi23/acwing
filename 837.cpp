//
// Created by LoadingV on 2025/7/19.
//
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N], s[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y){
    int x0 = find(x);
    int y0 = find(y);
    if(x0 != y0){
        p[y0] = x0;
        s[x0] += s[y0];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        s[i] = 1;
    }
    string opt;
    int x, y;
    while(m--){
        cin >> opt ;
        if(opt == "C"){
            cin >> x >> y;
            merge(x, y);
        }else if(opt == "Q1"){
            cin >> x >> y;
            cout << (find(x) == find(y) ? "Yes" : "No") << endl;
        }else{
            cin >> x;
            cout << s[find(x)] << endl;
        }
    }
    return 0;
}