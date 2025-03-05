#include<iostream>
using namespace std;
const int N = 100010;
int arr[N];

void quick_sort(int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, m = (l + r) >> 1;//������ôд��������ָ��������x = arr[l + r >> 1],�����10,11��ȡ���࣬��ʱ������ᷢ���仯�ģ�����ͱ䶯�� 
    while(i < j){
        do i ++; while(arr[i] < arr[m]);
        do j --; while(arr[j] > arr[m]);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    quick_sort(0, n - 1);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    return 0;
}
