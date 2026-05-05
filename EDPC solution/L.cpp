//注意区间dp枚举顺序，应该是先枚举区间长度，再枚举左端点/右端点
#include<bits/stdc++.h>
using namespace std;
int a[3005];
int k;
int n;
long long x;
long long y;
long long dp[3005][3005];
long long pre[3005];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(a[i] + (pre[j] - pre[i] - dp[i + 1][j]),a[j] + (pre[j - 1] - pre[i - 1] - dp[i][j - 1]));
        }
    }
    cout<<dp[1][n]-(pre[n]-dp[1][n]);
    return 0;
}