#include <iostream>
#include <climits>
using namespace std;

void swap(int & x, int & y) {
	int temp = x;
	x = y;
	y = temp;
	return;
}

class minHeap {
	int *harr;
	unsigned int capacity;
	int heap_size;
public:

	minHeap(int cap){
		heap_size = 0;
		capacity = capacity;
		harr = new int[cap];
	}

	int parent(int i) {
		return ((i-1)/2);
	}

	int left(int i) {
		return ((2*i)+1);
	}

	int right(int i) {
		return ((2*i)+2);
	}

	void insertKey(int k) {
		if (heap_size == capacity) {
			throw "Overflow!";
		}
		heap_size++;
		int i = heap_size -1 ;
		harr[i] = k;
		// Fix the mean heap property
		while(i != 0 && harr[parent(i)] > harr[i]) {
			swap(harr[i],harr[parent(i)]);
			i = parent(i);
		}
	}

	void decreaseKey(int i, int new_val) {
		harr[i] = new_val;
		while (i != 0 && harr[parent(i)] > harr[i]) {
			swap(harr[i],harr[parent(i)]);
			i = parent(i);
		}
	}

	

	int extractMin() {
		if (heap_size <= 0) {
			return INT_MAX;
		}
		if (heap_size == 1) {
			heap_size--;
			return harr[0];
		}
		int root = harr[0];
		harr[0] = harr[heap_size-1];
		heap_size--;
		minHeapify(0);
		return root;
	}

	void deleteKey(int i) {
		decreaseKey(i, INT_MIN);
		extractMin();
	}

	void minHeapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && harr[l] < harr[i]) {
			smallest = i;
		}
		if (r < heap_size && harr[r] < harr[i]) {
			smallest = r;
		}
		if (smallest != i) {
			swap(harr[i],harr[smallest]);
			minHeapify(smallest);
		}
	}

	int getMin() { return harr[0]; }
};

int main() {
	minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}