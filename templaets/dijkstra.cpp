#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=200005;
int n,m,s;
int head[N],ver[M],edge[M],ne[M];
int tot;
int dis[N];bool vis[N];
priority_queue<pair<int,int>> q;
void add(int u,int v,int w)
{
    ver[++tot]=v;edge[tot]=w;
    ne[tot]=head[u];head[u]=tot;
}
void dijkstra(int k)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[k]=0;
    q.push(make_pair(0,k));
    while(q.size())
    {
        int x=q.top().second;q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(int i=head[x];i;i=ne[i])
        {
            int y=ver[i],z=edge[i];
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                q.push(make_pair(-dis[y],y));
            }
        }
    }

}
int main(){
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}