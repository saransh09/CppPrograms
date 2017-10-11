#include <iostream>
using namespace std;

// int main() {
// 	int l,b,a;
// 	cin>>l>>b>>a;
// 	if(a>=l && a>=b){ 
// 		cout<<1;
// 		return 0;
// 	}
// 	if(a>l){ 
// 		int count = 0;
// 		for(int i = 0 ; i < b ; ){
// 			i += a;
// 			count++;
// 		}
// 		cout<<count;
// 		return 0;
// 	}
// 	if(a>b){ 
// 		int count = 0;
// 		for(int i = 0 ; i < l ; i++){
// 			i += a;
// 			count++;
// 		}
// 		cout<<count;
// 		return 0;
// 	}
// 	int count1 = 0,count2 = 0;
// 	for(int i = 0 ; i < l ; ){
// 		i += a;
// 		count1++;
// 	}
// 	for(int j = 0 ; j < b ;){
// 		j += a;
// 		count2++;
// 	}
// 	cout<<(long long)count1*count2;
// 	return 0;
// }

#include<iostream>
using namespace std;

int main() {
    int l,b,a;
    cin>>l>>b>>a;
    int m = 0, n = 0;
    if(l%a==0){
        m = l/a;
    }
    else{
        m = ((l - l%a) + a)/a;
    }
    if(b%a==0){
        n = b/a;
    }
    else{
        n = ((b - b%a) + a)/a;
    }
    cout<<(long long) n*m;
    return 0;
}