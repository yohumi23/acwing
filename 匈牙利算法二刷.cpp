//
// Created by LoadingV on 2025/8/26.
//
#include<iostream>
#include<cstring>
using namespace std;

int h[510], ne[100010], e[100010], idx = 0;
int match[510];
bool st[510];


void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int v = e[i];
        if(!st[v]){
            st[v] = true;
            if(match[v] == 0 || find(match[v])){
                match[v] = x;
                return true;
            }
        }
    }
    return false;
}




int main(){
    memset(h, -1, sizeof h);
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int sum = 0;
    for(int i = 1; i <= n1; i++){
        memset(st, 0, sizeof st);
        if(find(i)){
            sum++;
        }
    }
    printf("%d\n", sum);

    return 0;
}