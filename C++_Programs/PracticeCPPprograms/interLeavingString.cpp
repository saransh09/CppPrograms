#include <bits/stdc++.h>
using namespace std;

int calcLength(char *a) {
	int i = 0;
	while(*a!='\0') {
		i++;
		a++;
	}
	return i;
}

bool check(char *s1, char *s2, char *s3) {
	int l1 = calcLength(s1);
	int l2 = calcLength(s2);
	int l3 = calcLength(s3);
	int i=0,j=0,k=0;
	while(k<l3) {
		if (i!=l1){
			if(s3[k]==s1[i]) {
				k++;
				i++;
				// cout<<"k = "<<k<<' '<<"i = "<<i<<endl;
			}
		}
		if (j!=l2){
			if(s3[k]==s2[j]) {
				k++;
				j++;
				// cout<<"k = "<<k<<' '<<"j = "<<j<<endl;
			}
		}
	}
	if(k!=l3 || j!=l2 || i!=l1) {
			return false;
	}
	return true;
}

int main() {
	char s1[100],s2[100];
	cout<<"Enter the strings : \n";
	cin.getline(s1,100);
	cin.getline(s2,100);
	cout<<"Enter the string for the check : \n";
	char s3[100];
	cin.getline(s3,100);
	bool x = check(s1,s2,s3);
	if(x) {
		cout<<"It is an interleaving";
	}
	else {
		cout<<"It is not an interleaving";
	}
	return 0;
}