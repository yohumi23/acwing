#include<iostream>//��0Iһ���գ�ǧ���������ͷ

using namespace std;
//ע�⣡������x������float����Ȼ����˳�����1e-8��float������Զ�˲����������������� 

int main() {
	double x; 
	cin >> x;
	float l = 0, r = x;
	while(r - l >= 1e-8){
		double mid = (l + r) / 2;
		if(mid * mid >= x) r = mid;
		else l = mid;
	}
	cout << l << endl;
	return 0;
}


