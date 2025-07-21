//
// Created by LoadingV on 2025/7/20.
//
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100003;
int h[N], e[N], ne[N], idx = 0;

void myhash(int x){
    //考虑附属情况
    int k = ( x % N + N ) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool exists(int x){
    int k = ( x % N + N ) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x){
            return true;
        }
    }
    return false;
}

int n;
// 拉链法
int main(){
    // for(int i = 1e5; ; i++){
    //     bool flag = true;
    //     for(int j = 2; j * j <= i; j++){
    //         if(i % j == 0){
    //             flag = false;
    //             break;
    //         }
    //     }
    //     if(flag){
    //         printf("%d", i);
    //         break;
    //     }
    // }
    memset(h, -1, sizeof(h));
    int n, x;
    cin >> n;
    char opt;
    while(n--){
        scanf("%s%d", &opt, &x);
        if(opt == 'I'){
            myhash(x);
        }else{
            bool res = exists(x);
            cout << (res ? "Yes" : "No") << endl;
        }
    }


    return 0;
}