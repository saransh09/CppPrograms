#include <vector>
#include <list>
#include <iostream>
using namespace std;

list<int> * sortedMerge(list<int> *a,list<int> *b);
void frontBackSplit(list<int> *source, list<int> **frontRef, list<int> **backRef);

void mergeSort(list<int> **headref) {
	list<int> * head = *headref;
	list<int> *a;
	list<int> *b;

	if ((head==NULL) || (list<int>::iterator current == NULL)) {
		return;
	}

	frontBackSplit(head, &a, &b);

	mergeSort(&a);
	mergeSort(&b);

	*headref = sortedMerge(a,b);
}

list<int> * sortedMerge(list<int> *a, list<int> *b) {
	list<int> * result = NULL;

	if (a==NULL) {
		return b;
	}
	else if(b==NULL) {
		return a;
	}

	if ()
}

int main() {



	return 0;
}