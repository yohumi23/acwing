#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n, q;

int main() {
	scanf("%d%d", &n, &q);
	int target;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	while(q--) {
		scanf("%d", &target);
		int  l = 0, r = n - 1;
		while(l < r) {
		    int mid = l + r >> 1;
			if(a[mid] >= target) r = mid;
			else l = mid + 1;
		}
		if(a[l] != target) cout << "-1 -1" << endl;
		else {
		    cout << l << " ";
			l = 0, r = n - 1;
			while(l < r){
			    int mid = l + r + 1 >> 1;
			    if(a[mid] <= target) l = mid;
			    else r = mid - 1;
			}
			cout << l << endl;
		}
	}
	return 0;
}
