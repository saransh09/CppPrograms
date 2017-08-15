#include <list>
#include <iostream>
#include <vector>
using namespace std;


int main() {
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);
	l.push_back(11);
	list<int>::iterator it = l.begin();
	cout<<*it;
	while(it != l.end()) {
		if(*it == 5){
			break;
			// l.erase(it);
		}
		it++;
	}
	cout<<"New Value at it is : "<<*it;
	if(it==l.end()) {
		cout<<"Tu chutiya";
	}
	l.erase(it);
	cout<<endl;
	for(list<int>::iterator i = l.begin(); i != l.end() ; ++i) {
		cout<<*i<<' ';
	}
	return 0;
}