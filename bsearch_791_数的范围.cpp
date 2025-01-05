#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int q[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &q[i]);
	while(m --) {
		int k;
		scanf("%d", &k);
		int l = 0, r = n - 1;
		while(l < r) {
			//先找左边界
			//这个check是check保证答案在我们的范围内的。然后缩小范围找到边界点 
			int mid = l + r >> 1; 
			if(q[mid] >= k) r = mid;
			else l = mid + 1;
		}
		if(q[l] != k) cout << "-1 -1" << endl;
		else {
			cout << l << ' ';
			l = 0, r = n - 1;
			while (l < r) {
			    int mid = l + r + 1 >> 1;
				if(q[mid] <= k) l = mid;
				else r = mid - 1;
			}
			cout << l << endl;
		}

	}
	return 0;
}
