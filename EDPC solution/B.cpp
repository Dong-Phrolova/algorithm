#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int h[N];
int dp[N];
int n,k;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,0x3f,sizeof(dp));dp[1]=0;
    cin>>n>>k;
    for(int i =1;i<=n;i++){
        cin>>h[i];
        for(int j=max(1,i-k);j<i;j++)
            dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
    }
    cout<<dp[n];
}
//不可以用单调队列优化，因为abs(h[i]-h[j])与j有关，需要只与i有关
//可以用线段树优化,变成区间最小值查询和更新，之后再写