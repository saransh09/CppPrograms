#include <iostream>
#include <climits>
using namespace std;

template<typename T>

void swap(T & x, T & y) {
	T temp = x;
	x = y;
	y = temp;
	return;
}

template<typename T>

class minHeap {
	T * harr;
	unsigned int capacity;
	int heap_size;
public:

	minHeap(int cap) : capacity(cap), heap_size(0) {
		harr = new T[cap];
	}

	int parent(int i) {
		return (i-1)/2;
	}

	int left(int i) {
		return (2*i+1);
	}

	int right(int i) {
		return (2*i+2);
	}

	T getMin() {
		if(heap_size==0) {
			throw "Empty Heap";
		}
	}

	void insert(T key) {
		if(heap_size==capacity) {
			throw "Overflow!";
		}
		heap_size++;
		int i = heap_size-1;
		harr[i] = key;
		while(i!=0 && harr[parent(i)] > harr[i]) {
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
	}

	void decreaseKey(int i, int new_val) {
		harr[i] = new_val;
		while(i!=0 && harr[parent(i)] > new_val) {
			swap(harr[parent(i)],harr[i]);
		}
	}

};

int main() {


	return 0;
}