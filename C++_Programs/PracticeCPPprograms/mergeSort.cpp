#include <iostream>
using namespace std;

void merge(int *arr,int start,int end) {
	int mid = (start + end)/2;
	int k=0, i=start, j=mid+1;
	int temp[10000];
	while (i <= mid && j <= end) {
		if (arr[i]<arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while ( i <= mid ){
		temp[k++] = arr[i++];
	}
	while ( j <= end) {
		temp[k++] = arr[j++];
	}
	for (int k=start; k<=end;k++) {
		arr[k] = temp[k-start];
	}
}

void mergeSort(int *arr, int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end)/2;
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	merge(arr,start,end);
}

int main() {

	int a[10] = {5,1,8,4,2,9,-23,-1,23,1};
	for (int i=0;i<10;i++) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
	mergeSort(a,0,9);
	for (int i=0;i<10;i++) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}