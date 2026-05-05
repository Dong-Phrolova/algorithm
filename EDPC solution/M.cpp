//dp在设计状态和实现的时候，有两种方式，一种是考虑当前状态能更新后边哪些状态；一种是考虑当前状态可以由哪些之前的状态更新
//若当前状态可以由上一行/之前的连续一段状态的和更新，可以考虑前缀和优化
//空间可进一步压缩一维
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[105];
long long dp[105][100005];
long long pre[100005];
int n,k;
long long getsum(int l,int r)
{
    return (l==0?pre[r]:(pre[r]-pre[l-1]+mod)%mod)%mod;
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        pre[0]=dp[i-1][0];//或pre[0]=1;
        for(int j=1;j<=k;j++)pre[j]=(pre[j-1]+dp[i-1][j])%mod;

        for(int j=0;j<=k;j++){
            dp[i][j]=getsum(max(0,j-a[i]),j);
        }
    }
    cout<<dp[n][k];
    return 0;
}