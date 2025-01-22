#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int arr[N];
int arr2[N];

void find_range(int q[], int target, int l, int r) {
	//���ҵ�start
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
			if(q[mid] <= target) i = mid;//������������ұ��ƶ���, i = mid��ʾȡ�ұ����� 
			else j = mid - 1; //�����ʾȡ������䣬��Ȼ�� j = mid - 1�ˣ��ܵ���˵��[left, mid-1] [mid,right] 
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
