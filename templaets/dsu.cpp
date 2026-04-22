#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=1000005;
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
        if(siz[a]!=siz[b])
        {
            if(siz[a]<siz[b])swap(a,b);
            fa[b]=a;
            siz[a]+=siz[b];
            cnt--;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){fa[i]=i;cnt=n;siz[i]=1;}
    for(int i=0;i<n;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            merge(x,y);
        }
        else {
            if(get(x)==get(y))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}