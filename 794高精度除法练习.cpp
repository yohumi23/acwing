#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> div(vector<int> &B, int c, int &y) {// yÊÇÒıÓÃ 
	vector<int> C;
	y = 0;
	for(int i = B.size() - 1; i >= 0; i--) {
		y  = y * 10   + B[i] ;
		C.push_back(y / c);
		y = y % c;
	}
	reverse(C.begin(), C.end());
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main() {
	string b;
	int c;
	cin >> b >> c;
	vector<int> B;
	for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	int y;
	auto C = div(B, c, y);
	for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	cout << endl << y << endl;
	return 0;
}


