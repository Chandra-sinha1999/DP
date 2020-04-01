#include<bits/stdc++.h>
using namespace std;
int main(void){
    string a,b;
    cin>>a>>b;
    int len1 = a.length();
    int len2 = b.length();
    vector< vector <int> > dp(len1 + 1,vector<int>(len2 + 1));
    for(int i = 0; i <= len1; i++) dp[i][0] = 0;
    for(int j = 0; j <= len2; j++) dp[0][j] = 0;
    for(int i = 1;i <= len1; i++){
        for(int j = 0;j <= len2; j++){
           if(a[i - 1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
		   else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
	string s = "";
	int len = dp[len1][len2];
	int i = len1 , j = len2;
	while(i > 0 && j > 0){
		if(a[i-1] == b[j-1]) {
			s = s + a[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else j--;
	}
	reverse(s.begin(),s.end());
	cout << s << endl;
}
