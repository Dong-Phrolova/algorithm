#include<bits/stdc++.h>
using namespace std;
const int N=3e2+10;
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
int a[4];

double dp[N][N][N];
double p[N];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        a[t]++;
    }
     for (int k = 0; k <= n; k++) {
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                if (i + j + k == 0 || i + j + k > n) continue;
                double res = n;
                if (i > 0) res += i * dp[i - 1][j][k];
                if (j > 0) res += j * dp[i + 1][j - 1][k];
                if (k > 0) res += k * dp[i][j + 1][k - 1];
                dp[i][j][k] = res / (i + j + k);
            }
        }
    }
    printf("%.10f",dp[a[1]][a[2]][a[3]]);
    return 0;
}