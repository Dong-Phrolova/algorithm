#include<iostream>
using namespace std;
const int N=1e5+10;
int h[N];
int dp[N];
int n;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>h[1]>>h[2];
    dp[1]=0;dp[2]=abs(h[1]-h[2]);
    for(int i =3;i<=n;i++){
        cin>>h[i];
        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<dp[n];
    
}