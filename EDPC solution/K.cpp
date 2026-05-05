#include<bits/stdc++.h>
using namespace std;
int a[101];
int k;
int n;
int dp[100005];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i-a[j]>=0)
            dp[i]=dp[i]|(!dp[i-a[j]]);
        }
    }
    if(dp[k])cout<<"First";
    else cout<<"Second";
    return 0;
}