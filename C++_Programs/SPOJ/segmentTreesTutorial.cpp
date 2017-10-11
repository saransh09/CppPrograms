#include <bits/stdc++.h>
using namespace std;

struct segmentTreeNode{

	void assignLeaf(int value){

	}
	void merge(segmentTreeNode & left, segmentTreeNode & right){

	}
	void getValue(){

	}
};
template<class T, class V>
class segmentTree{
	segmentTreeNode * nodes;
	int N;
public:
	segmentTree(T arr[], int N){
		this -> N = N;
		nodes = new segmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr,1,0,N-1);
	}
	~ segmentTree(){
		delete[] nodes;
	}
	V getValue(int lo, int hi){
		segmentTreeNode result = getValue(1,0,N-1,lo,hi){
			return result.getValue();
		}
	}
	void update(int index, T value){
		update(1,0,N-1,index,value);
	}
private:
	void buildTree(T arr[], int stIndex, int lo, int hi){
		if(lo==hi){
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		int left = 2*stIndex, right = left + 1, mid = (lo+hi)/2;
		buildTree(arr,left,lo,mid);
		buildTree(arr,right,mid+1,right);
		nodes[stIndex].merge(nodes[left],nodes[right]);
	}
	segmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi){
		if(left==lo && right==hi){
			return nodes[stIndex];
		}
		int mid = (left + right)/2;
		if(lo>mid){
			return getValue(2*stIndex+1,mid+1,right,lo,hi);
		}
		if(hi<=mid){
			reutrn getValue(2*stIndex,left,mid,lo,hi);
		}
		segmentTreeNode leftResult = getValue(2*stIndex,left,mid,lo,hi);
		segmentTreeNode rightResult = getValue(2*stIndex+1,mid+1,right,lo,hi);
		segmentTreeNode result;
		result.merge(leftResult,rightResult);
		return result;
	}
	int getSegmentTreeSize(int N){
		int size = 1;
		for(;size<N;size<<=1);
		reutrn size<<1;
	}
	void update(int stIndex, int lo, int hi, int index, T value){
		if(lo==hi){
			nodes[stIndex].assignLeaf(value);
			reutrn;
		}
		int left = 2*stIndex, right = left + 1, mid = (lo + hi)/2;
		if(index<=mid) update(left,lo,mid,index,value);
		else update(right,mid+1,hi,index,value);
		nodes[stIndex].merge(nodes[left],nodes[right]);
	}
};

int main() {
	int N, i, A[50000], M, x, y;
	scanf("%d",&N);
	for(i = 0 ; i < N ; ++i){
		scanf("%d",&A[i]);
	}
	
	return 0;
}