#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=200005;
int n,m;
int fa[N];
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
int siz[N],cnt;//连通块大小和个数
void merge(int x,int y){
    //fa[get(x)]=get(y);
    int a=get(x);
    int b=get(y);
    if(a!=b)
    {
        if(siz[a]<siz[b])swap(a,b);
        fa[b]=a;
        siz[a]+=siz[b];
        cnt--;
    }
}
struct rec{
    int x,y,z;
}edge[M];
bool operator <(rec a,rec b)
{
    return a.z<b.z;
}
int ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){fa[i]=i;cnt=n;siz[i]=1;}
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
    }
    sort(edge+1,edge+m+1);
    for(int i=1;i<=m;i++){
        int x=get(edge[i].x);
        int y=get(edge[i].y);
        if(x==y)continue;
        merge(x,y);
        ans+=edge[i].z;
    }
    if(cnt!=1)printf("orz");
    else printf("%d",ans);
    return 0;
}