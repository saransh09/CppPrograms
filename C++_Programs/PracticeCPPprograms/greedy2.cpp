#include <algorithm>
#include <iostream>
using namespace std;

class Activity {
public:
	int start,finish;
};

bool activityCompare(Activity s1, Activity s2) {
	return (s1.finish < s2.finish);
}

void printMaxActivities(Activity arr[], int n) {
	sort(arr,arr+n,activityCompare);
	cout<<"The following activities are selected : ";
	int i = 0;
	cout << '(' << arr[i].start << ", " << arr[i].finish << "), ";
	for (int j = 1; j < n; j++) {
		if (arr[j].start >= arr[i].finish) {
			
		}
	}
}

int main() {


	return 0;
}