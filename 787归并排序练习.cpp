#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int q[N];

void merge_sort(int q[], int l, int r) {
	if(l >= r) return; 
	int mid = l + r >> 1;
	int c[N];
	int t = 0;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int i = l, j = mid + 1;
	for(; i <= mid && j <= r; ){
		if(q[i] <= q[j]) c[t++] = q[i++];
		else c[t++] = q[j++];
	}
	while(i <= mid) c[t++] = q[i++];
	while(j <= r) c[t++] = q[j++];
	//要注意的是这个临时的数组怎么转移值的过程，每次迭代只会保证区间[l,r]内的元素有序，且保存在c临时数组中，需要把临时数组的放置到原数组中 
	for(i = l, j = 0; i <= r; i++, j++) q[i] = c[j];
}


int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &q[i]);
	}
	merge_sort(q, 0, n-1);
	for(int i=0; i<n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}
