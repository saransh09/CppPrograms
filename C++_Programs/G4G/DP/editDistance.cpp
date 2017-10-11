#include <bits/stdc++.h>
using namespace std;

class Solution{
	int editDistanceHelper(string a, string b, int n, int m){
		if(m==0) return n;
		if(n==0) return m;
		if(a[n-1]==b[m-1]) return editDistanceHelper(a,b,n-1,m-1);
		return 1 + min(editDistanceHelper(a,b,n-1,m-1),min(editDistanceHelper(a,b,n-1,m),editDistanceHelper(a,b,n,m-1)));
	}
	int editDistanceHelperDP(string a, string b){
		int dp[a.length()+1][b.length()+1];
		dp[0][0] = 0;
		for(int i = 0 ; i <= a.length() ; i++){
			for(int j = 0 ; j <= b.length() ; j++){
				if(i==0) dp[i][j] = j;
				else if(j==1) dp[i][j] = i;
				else if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
		return dp[a.length()][b.length()];
	}
public:
	int editDistance(string a, string b){
		return editDistanceHelperDP(a,b);
	}
};

int main() {
	// string a = "sundayaskdjasiofhoisdjoiaradioajdioasjdoiajsdoiasjdioajsdioajsdoiajsoagjoisdjgsdoifjaoifjasoidjsaoidjasoidjasoidjiaosjdoiasdjaiosdjiaosdjoiasdjioasdjoiasdjaoijsdioasdjoiasjdoiasjdoiasjdoiasjdoiahgoidvboivbojsvbaofbuefbuoqebhjoiwjeofkjdokfjoaifjaoidjsaopdjoiajsdpiasjdaisdjsapihgpiahspgajksfpkfpoaskdpfaskfdsajdasjdasj";
	// string b = "saturdayaoidjasiodjaoijdaiosdjoaijoiasdjoiarjoiajfoiajfoiahtoiejriawjfsjfioasfjoaifjasoifasjiofsajiofsaoijfsaijofsaijoasijhdifcnhsaiubhaivuhnaifnueibequifguieorjoerweoiugfwuoiueraiuiurrieureiuorreruyreyreugyrighreigheiuvhiuerhviueheiuhvriuhiuhiuvhihiooireugoijvoidjfoiewjfoiwefjweoijweoijefoijweofejoiwefjoiwejfoiwejfasjifasj";
	string s1 = "food";
	string s2 = "money";
	Solution s;
	cout<<s.editDistance(s1,s2)<<endl;
	return 0;
}