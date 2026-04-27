#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=1e3+10;
const int MOD=1e9+7;

int tot;
int ne[M],head[N],ver[M];
int deg[N],d[N];
void add(int x,int y){
    ver[++tot]=y;ne[tot]=head[x];head[x]=tot;
}
queue<int> q;

int n,m;
int ans;
int a[N][M];

long long dp[N][M];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char s;
            cin>>s;
            if(s=='#'){
                a[i][j]=0;
                dp[i][j]=0;
            }
            else{
                a[i][j]=1;
                dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}