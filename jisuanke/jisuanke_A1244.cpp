#include<cstdio>
#include<iostream>
#include<cstring>
#define INF 1000000000000000
#include<queue>
#define ll long long
#define N 200005
using namespace std;
int head[N*4],s;
queue<int>q;
ll dis[N*4],vis[N*4];
struct edge{
    int to,nex,len;
}e[N*4];
void ins(int x,int y,int len){
    e[++s].nex=head[x];
    e[s].to=y;
    e[s].len=len;
    head[x]=s;
}
void dijkstra(int S){
    for(int i=0;i<N*4;i++)
        dis[i]=INF;
    memset(vis,0,sizeof(vis));
    dis[S]=0;
    vis[S]=1;
    q.push(S);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=e[i].nex){
            int y=e[i].to;
            if(dis[x]+e[i].len<dis[y]){
                dis[y]=dis[x]+e[i].len;
                if(!vis[y]){
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}
int main(){
    // freopen("Ain.txt","r",stdin);
    int n,m,m1,m2,x,y,len,st,en;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int n_city,city;
        scanf("%d",&n_city);
        while(n_city--){
            scanf("%d",&city);
            ins(i+N,city,0);
            ins(city,i+2*N,0);
        }
    }
    cin>>m1;
    for(int i=1;i<=m1;i++){
        scanf("%d %d %d",&x,&y,&len);
        ins(x,y,len);
        ins(y,x,len);
    }
    cin>>m2;
    for(int i=1;i<=m2;i++){
        scanf("%d %d %d",&x,&y,&len);
        ins(x+2*N,y+N,len);
        ins(y+2*N,x+N,len);
    }
    cin>>st>>en;
    dijkstra(st);
    if(dis[en]==INF)
        cout<<-1;
    else
        cout<<dis[en];
    return 0;
}