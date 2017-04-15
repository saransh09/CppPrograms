#include <iostream>
using namespace std;

class stack {
	int top;
	unsigned capacity;
	int *array;
public:
	stack(unsigned cap) {
		if (stack) {
			throw "The stack already exists ";
		}
		capacity = cap;
		array = new int[capacity];
		stack->top = -1;
		return stack;
	}
	int isEmpty(stack * S) {
		if (S -> stack -> top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	int peep(stack * S) {
		S -> array[S -> top] ;
	}
	char pop()

};

int main() {

	return 0;
}