#include<iostream>
#include<vector>

using namespace std;

const int N = 1e6 + 10;

vector<int> add(vector<int> &A, vector<int> &B) {
	int s = 0;
	vector<int> C;
	for(int i = 0, j = 0; i < A.size() || j < B.size(); i++, j++) {
		if(i < A.size()) s += A[i];
		if(j < B.size()) s += B[j];
		C.push_back(s % 10);
		s /= 10;
	}
	if(s) C.push_back(s);
	return C;
}


int main() {
	string a, b;
	cin >> a >> b;
	vector<int> A, B;
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	auto C = add(A, B);
	for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	return 0;
}
