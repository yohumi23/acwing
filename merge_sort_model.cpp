#include<iostream>//不0I一场空，千万别用万能头

using namespace std;

const int N = 1e6 + 10;
int q[N], tmp[N];
int n;

void merge_sort(int q[], int l, int r){
	if( l >= r) return;
	int mid = l + r >> 1;
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while(i <= mid && j <= r){
		if(q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while(i <= mid) tmp[k++] = q[i++];
	while(j <= r) tmp[k++] = q[j++];
	for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}


int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}
	merge_sort(q, 0, n - 1);
	for(int i = 0; i < n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}


