#include<iostream>
#include<vector>
using namespace std;

vector<int> add(vector<int>& A, vector<int>& B){
    int s = 0;
    vector<int> C;
    for(int i = 0; i < A.size() ||  i < B.size(); i++){
        if(i < A.size()) s += A[i];
        if(i < B.size()) s += B[i];
        C.push_back(s % 10);
        s /= 10;
    }
    //不能忘记最后一次进位！！！ 
    if(s) C.push_back(s);
    return C;
}

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C =  add(A, B);
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
}
