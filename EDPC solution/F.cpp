#include<bits/stdc++.h>
using namespace std;
string s,t;
vector<char>ans;
const int N=3005;
int dp[N][N];
int main(){
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    while(n>0&&m>0)
    {
        if(s[n-1]==t[m-1]){
                ans.push_back(s[n-1]);
                m--;n--;
            }
            else if(dp[n-1][m]>dp[n][m-1])
            {
                n--;
            }
            else m--;
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
}