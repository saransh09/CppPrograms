#include <iostream>
using namespace std;

class twoStacks {
	int *arr;
	int size;
	int top1, top2;
public:
	twoStacks(int n) {
		if (arr) {
			throw "The twoStack already exists";
		}
		size = n;
		arr = new int[size];
		top1 = -1;
		top2 = size;
	}
	void push1(int x) {
		if (top1 < top2 - 1){
			top1 ++;
			arr[top1] = x;
		}
	}
	else{
		throw "Stack overflow";
	}
	void push2(int x) {
		if (top 1 < top2 - 1) {
			top2 --;
			arr[top2] = x;
		}
		else {
			throw "Stack overflow";
		}
	}
	
};

int main() {

	return 0;
}