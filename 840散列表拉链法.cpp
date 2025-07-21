#include<iostream>
#include<cstring>
using namespace std;
const int N = 200003, nil = 0x3f3f3f3f;
int h[N];

bool find(int x){
    int k = ( x % N + N ) % N;
    while(h[k] != nil && h[k] != x){
        k++;
        if(k == N) k = 0;
    }
    return k;
}


int main(){
    memset(h, 0x3f, sizeof(h));
    int n, x;
    cin >> n;
    char opt;
    while(n--){
        cin >> opt >> x;
        if(opt == 'I'){
            int p = find(x);
            h[p] = x;
        }else{
            int p = find(x);
            if(p == nil){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }
    }
    return 0;
}