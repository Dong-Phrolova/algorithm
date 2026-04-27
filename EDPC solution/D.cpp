#include<bits/stdc++.h>
using namespace std;
const int N=105,W=1e5+5;//重量较小，价值大，dp[w]表示当前重量下最大的价值
long long dp[W],a[N],b[N];
int n,w;
int main()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=w;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
        }
    }
    cout<<dp[w];
    return 0;
}