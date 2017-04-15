#include <iostream>
using namespace std;

// int * tempCreator(int start, int end) {
// 	int * temp = new int[end-start+1];
// 	return temp;
// }

// int sum=0;

void mergeSorted(int *arr, int start, int end,int & sum) {
	int mid = (start+end)/2;
	int i=start,j=mid+1,k=0;
	int temp[10000];
	while( i<=mid && j <= end) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			sum += mid - start + 1;
		}
	}
	while ( i <= mid ) {
		temp[k++] = arr[i++];
	}
	while ( j <= end ) {
		temp[k++] = arr[j++];
	}
	for(int k=start;i<end;i++) {
		arr[k] = temp[k-start];
	}
};

void mergeAndCountSplitInversions(int *arr,int start,int end, int & sum) {
	if(start==end){
		return;
	}
	int mid = ((start)+(end))/2;
	mergeAndCountSplitInversions(arr,start,mid,sum);
	mergeAndCountSplitInversions(arr,mid+1,end,sum);
	mergeSorted(arr,start,end,sum);
}


int main() {
	int arr[5] = {8,4,2,1};
	int sum;
	sum = 0;
	mergeAndCountSplitInversions(arr,0,3,sum);
	for (int i=0;i<4;i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	cout<<"The number of split inversions is : "<<sum;
	return 0;
}