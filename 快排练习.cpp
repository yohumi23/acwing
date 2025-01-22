#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int q[N];

void quick_sort(int q[], int l, int r) {
	if(l >= r) return;
	int i = l - 1, j = r + 1, x = q[l + r >> 1];//����x��ȡֵ�кིܶ�������ȡq[l]�ͻᳬʱ�������������ͻ���������Ҫ���õ����ε�˼�� 
	while(i < j) {
		do i++ ;
		while(q[i] < x);
		do j--;
		while(q[j] > x);
		if(i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j); //����������ȡ�������ǵ��߽����⣬1.[l,j][j+1,r] 2.[l,i-1][i,r] 
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
