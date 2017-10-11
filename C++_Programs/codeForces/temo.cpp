#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[1009][1009];
int dp2[1009][1009];
int dp5[1009][1009];
int n;
int fn2(int x)
{
	int cnt=0;
	while(x%2==0){cnt++;x/=2;}
	return cnt;
}
int fn5(int x)
{
	int cnt=0;
	while(x%5==0){cnt++;x/=5;}
	return cnt;
}
int main()
{
	cin >> n ;
	int i,j,hv=0;
	int p,q;
	for(i=0;i<n;i++){for(j=0;j<n;j++){scanf("%d",&a[i][j]); if(a[i][j]==0){hv=1;a[i][j]=10;p=i;q=j;}}}
	dp2[0][0]=fn2(a[0][0]);dp5[0][0]=fn5(a[0][0]);
	for(i=1;i<n;i++)
	{
		dp2[0][i]=fn2(a[0][i])+dp2[0][i-1];
		dp5[0][i]=fn5(a[0][i])+dp5[0][i-1];
		dp2[i][0]=fn2(a[i][0])+dp2[i-1][0];
		dp5[i][0]=fn5(a[i][0])+dp5[i-1][0];
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			dp2[i][j] = fn2(a[i][j])+min(dp2[i-1][j],dp2[i][j-1]) ;
			dp5[i][j] = fn5(a[i][j])+min(dp5[i-1][j],dp5[i][j-1]) ;
		}
	}
	string y="";
	if(dp2[n-1][n-1] < dp5[n-1][n-1])
	{
		i=n-1;
		j=n-1;
		while(i+j!=0)
		{
			if(i==0){ y+='R'; j--;}
			else if(j==0){y+='D';i--;}
			else if(dp2[i-1][j]<dp2[i][j-1])
			{
				 i--;
				 y+='D';
			}
			else
			{
				 j--;
				 y+='R';
			}
		}
	}
	else
	{
		i=n-1;
		j=n-1;
		while(i+j!=0)
		{
			if(i==0){ y+='R'; j--;}
			else if(j==0){y+='D';i--;}
			else if(dp5[i-1][j]<dp5[i][j-1])
			{
				 i--;
				 y+='D';
			}
			else
			{
				 j--;
				 y+='R';
			}
		}
	}
	reverse(y.begin(),y.end());
	int ans= min(dp2[n-1][n-1],dp5[n-1][n-1]);
	if(ans>0 && hv==1)
	{
		cout << 1 << endl;
		string z="";
		int e=0;
		while(e!=p){ z+='D';e++;}
		e=0;
		while(e!=n-1){ z+='R';e++;}
		while(p!=n-1){ z+='D';p++;}
		cout << z << endl;
	}
	else
	{
		cout << ans << endl << y << endl;
	}
	return 0;
}