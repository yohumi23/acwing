#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int q[N];

void quick_sort(int q[], int l, int r) {
	if(l >= r) return;
	int i = l - 1, j = r + 1, x = q[l + r >> 1];//关于x的取值有很多讲究，如果取q[l]就会超时，如果本身有序就会很慢，最好要利用到分治的思想 
	while(i < j) {
		do i++ ;
		while(q[i] < x);
		do j--;
		while(q[j] > x);
		if(i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j); //区间有两种取法，考虑到边界问题，1.[l,j][j+1,r] 2.[l,i-1][i,r] 
	quick_sort(q, j+1, r);
}


int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &q[i]);
	}
	quick_sort(q, 0, n-1);
	for(int i=0; i<n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}
