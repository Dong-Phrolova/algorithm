#include<bits/stdc++.h>
using namespace std;
const int N=105,V=1e5+5;//重量较大，价值小，dp[v]表示达到这个价值最小的重量
long long dp[V],a[N],b[N];
int n,w;    
int sum;
int main()
{
    cin>>n>>w;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=b[i];j--){
            dp[j]=min(dp[j],dp[j-b[i]]+a[i]);
        }
    }
    for(int i=sum;i>=0;i--)
    {
        if(dp[i]<=w){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}