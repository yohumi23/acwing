#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int arr[N];
int arr2[N];

void find_range(int q[], int target, int l, int r) {
	//先找到start
	int i = l, j = r;
	while (i < j) {
		int mid = i + j >> 1;
		if(q[mid] >= target) j = mid;
		else i = mid + 1;
	}
	if(q[i] != target) cout << "-1 -1" << endl;
	else {
		cout << i << " ";
		i = l, j = r;
		while(i < j) {
			int mid = i + j + 1 >> 1;
			if(q[mid] <= target) i = mid;//这个是区间向右边移动了, i = mid表示取右边区间 
			else j = mid - 1; //这个表示取左边区间，自然是 j = mid - 1了，总的来说是[left, mid-1] [mid,right] 
		}
		cout << i << endl;
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for(int i = 0; i < q; i++) {
		scanf("%d", &arr2[i]);
	}
	for(int i = 0; i < q; i++) {
		find_range(arr, arr2[i], 0, n - 1);
	}
}
