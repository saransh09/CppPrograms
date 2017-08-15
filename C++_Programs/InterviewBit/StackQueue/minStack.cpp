#include <bits/stdc++.h>
using namespace std;

class minStack {
private:
	stack<int> elementStack;
	stack<int> minStack;
	int minElement = -1;
public:
	void push(int x) {
		elementStack.push(x);
		if (elementStack.size() == 1 || x <= minElement) {
			minStack.push(x);
			minElement = x;
		}
	}
	void pop() {
		if (elementStack.top() == minElement) {
			minStack.pop();
			if (!minStack.empty()) {
				minElement = minStack.top();
			}
			else {
				minElement = -1;
			}
		}
		elementStack.pop();
	}
	int top() {
		if (elementStack.empty()) {
			return -1;
		}
		return elementStack.top();
	}
	int getMin() {
		return minElement;
	}
}; 

int main() {

	return 0;
}