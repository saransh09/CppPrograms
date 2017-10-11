#include <bits/stdc++.h>
using namespace std;

struct segmentTreeNode{
	int prefixSum, suffixSum, maxSum, sum;
	void assignLeaf(int value){
		prefixSum = suffixSum = maxSum = sum = value;
	}
	void merge(segmentTreeNode & left, segmentTreeNode & right){
		sum = left.sum + right.sum;
		prefixSum = max(left.prefixSum,left.sum + right.prefixSum);
		suffixSum = max(right.prefixSum, right.sum + left.prefixSum);
		maxSum = max(prefixSum, max(suffixSum, max(left.maxSum, max(right.maxSum, max(left.suffixSum, right.prefixSum)))));
	}
	int getValue() return maxSum;
};

template<class T, class V>
class segmentTree{
	segmentTreeNode * nodes;
	int N;
public:
	segmentTree(T arr[], int N){
		this->N = N;
		nodes = new segmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr,1,0,N-1);
	}
	~segmentTree(){
		delete[] nodes;
	}
	V getValue(int lo, int hi){
		segmentTreeNode result = getValue(1,0,N-1,lo,hi);
		return result.getValue();
	}
	void update(int index, T value){
		update(1,0,N-1,index,value);
	}
private:
	void buildTree(T arr[], int stIndex, int lo, int hi){
		if(lo==hi){
			nodes[stIndex].assignLeaf(arr[lo]);
		}
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi)/2;
		buildTree(arr,left,lo,mid);
		buildTree(arr,right,mid+1,hi);
		nodes[stIndex].merge(nodes[left],nodes[right]);
	}
	segmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi){
		if(left==lo && right==hi) return stIndex;
		int mid = (left+right)/2;
		if(lo>mid) return getValue(2*stIndex+1,mid+1,right,lo,hi);
		if(hi<=mid) return getValue(2*stIndex,left,mid,lo,hi);
		segmentTreeNode leftResult = getValue(2*stIndex,left,mid,lo,hi);
		segmentTreeNode rightResult = getValue(2*stIndex,mid+1,right,lo,hi);
		segmentTreeNode result;
		result.merge(leftResult,rightResult);
		return result;
	}
	int getSegmentTreeSize(int N){
		int size = 1;
		for(;size<N ; size<<=1);
		return size<<1;
	}
	void update(int stIndex, int lo, int hi, int index, T value){
		if(lo==hi){
			nodes[stIndex].assignLeaf(value);
			return;
		}
		int left = 2*stIndex, right = left + 1,  
	}
};

int main() {

	return 0;
}