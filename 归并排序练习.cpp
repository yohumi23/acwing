#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int q[N];
int tmp[N];

void merge_sort(int l, int r) {
	if(l >= r) return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	for(; i <= mid, j <= r; ) {
		if(q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while(i <= mid) tmp[k++] = q[i++];
	while(j <= r) tmp[k++] = q[j++];
	for(int i = l, k = 0;  i <= r; i++) q[i] = tmp[k++];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &q[i]);
	merge_sort(0, n - 1);
	for(int i = 0; i < n; i++) printf("%d ", q[i]);

	return 0;
}
