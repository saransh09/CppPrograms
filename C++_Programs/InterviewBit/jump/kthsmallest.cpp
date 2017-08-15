// A C++ program to find k'th smallest element using min heap
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
 
// A class for Min Heap
class MinHeap
{
    vector<int> harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(const vector<int> a, int size); // Constructor
    void MinHeapify(int i);  //To minheapify subtree rooted with index i
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
 
    int extractMin();  // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};
 
MinHeap::MinHeap(vector<int> a, int size)
{
    heap_size = size;
    harr.resize(size);
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;
 
    // Store the minimum vakue.
    int root = harr[0];
 
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        MinHeapify(0);
    }
    heap_size--;
 
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// Function to return k'th smallest element in a given array
int kthSmallest(const vector<int> arr, int n, int k)
{
    // Build a heap of n elements: O(n) time
    MinHeap mh(arr, n);
 
    // Do extract min (k-1) times
    for (int i=0; i<k-1; i++)
        mh.extractMin();
 
    // Return root
    return mh.getMin();
}
 
// Driver program to test above methods
int main()
{
    int arr[] = {81, 92};
    vector<int> a;
    a.push_back(8);
    a.push_back(16);
    a.push_back(80);
    a.push_back(55);
    a.push_back(32);
    a.push_back(8);
    a.push_back(38);
    a.push_back(40);
    a.push_back(65);
    a.push_back(18);
    a.push_back(15);
    a.push_back(45);
    a.push_back(50);
    a.push_back(38);
    a.push_back(54);
    a.push_back(52);
    a.push_back(23);
    a.push_back(74);
    a.push_back(81);
    a.push_back(42);
    a.push_back(28);
    a.push_back(16);
    a.push_back(66);
    a.push_back(35);
    a.push_back(91);
    a.push_back(36);
    a.push_back(44);
    a.push_back(9);
    a.push_back(85);
    a.push_back(58);
    a.push_back(59);
    a.push_back(49);
    a.push_back(75);
    a.push_back(20);
    a.push_back(87);
    a.push_back(60);
    a.push_back(17);
    a.push_back(11);
    a.push_back(39);
    a.push_back(62);
    a.push_back(20);
    a.push_back(17);
    a.push_back(46);
    a.push_back(26);
    a.push_back(81);
    a.push_back(92);
    // int n = sizeof(arr)/sizeof(arr[0]), k = 9;
    int k = 9;
    cout << "K'th smallest element is " << kthSmallest(a, a.size(), k);
    return 0;
}