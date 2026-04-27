#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
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
double pro;
int a[N][M];

double dp[N];
double p[N];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int k=i;k>=0;k--)
        {
            if (k == 0) 
                dp[k] = dp[k] * (1 - p[i]);
            else 
                dp[k] = dp[k] * (1 - p[i]) + dp[k - 1] * p[i];
        }
    }
    for(int i=(n+1)/2;i<=n;i++)pro+=dp[i];
    printf("%.10f",pro);
    return 0;
}