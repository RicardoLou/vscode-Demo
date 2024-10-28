#include<stdio.h>
#include<stdlib.h>
void selection_sort(int arr[], int n) {
	for(int i = 0; i < n - 1; i ++) {
		int min = i;
		//从i以后的数开始匹配，遇到更小的就交换
		for(int j = i + 1; j < n; j ++) {
			if(arr[j] < arr[min]) min = j;
			//swap
			arr[i] += arr[min];
			arr[min] = arr[i] - arr[min];
			arr[i] = arr[i] - arr[min];
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);
	selection_sort(arr, n);
	for(int i = 0; i < n; i ++) printf("%d ",arr[i]);
}
