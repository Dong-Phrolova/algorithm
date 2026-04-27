#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e5+10;
int ans;
int n,m;
int x,y;
int tot;
int ne[M],head[N],ver[M];
int deg[N],d[N];
void add(int x,int y){
    ver[++tot]=y;ne[tot]=head[x];head[x]=tot;
}
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i =1;i<=m;i++){
        cin>>x>>y;
        add(x,y);
        deg[y]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
            d[i]=0;
        }
    }
    while(!q.empty()){
        int z=q.front();
        q.pop();
        for(int i=head[z];i;i=ne[i])
        {
            int w=ver[i];
            d[w]=d[z]+1;
            ans=max(ans,d[w]);
            if(--deg[w]==0){
                q.push(w);
            }
        }
    }
    cout<<ans;
    
}