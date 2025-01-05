#include<iostream>//不0I一场空，千万别用万能头

using namespace std;
//注意！！这里x必须是float，不然你的退出条件1e-8在float里面永远退不出来。。。。。。 

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


