#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<set>
#define INF 1000000000
#define N 500005
using namespace std;
int n,k;
long long a,b;
int dis[N],head[N],num;
set<int>s[N];
struct edge{
    int to,nex;
}e[N*2];
void ins(int x,int y){
    e[++num].nex=head[x];
    e[num].to=y;
    head[x]=num;
}
long long bfs1(){
    queue<int>q;
    q.push(1);
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=head[x];i;i=e[i].nex){
            int v = e[i].to;
            if(dis[v]!=-1) continue;
            dis[v]=dis[x]+1;
            q.push(v);
            if(v==n)
                return dis[v];
        }
    }
    return INF;
}
int L[N],R[N];
long long bfs2(){
    for(int i=1;i<=n;i++)
        L[i]=i-1,R[i]=i+1;
    queue<int>q;
    q.push(1);
    if(s[1].size()==n-1)
        return INF;
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int v=R[1];v!=n+1;v=R[v]){
            if(s[x].count(v)) continue;
            if(dis[v]!=-1) continue;
            dis[v]=dis[x]+1;q.push(v);
            if(v==n)
                return dis[v];
            L[R[v]]=L[v];R[L[v]]=R[v];
        }
    }
    return INF;
}
int main(){
    cin>>n>>k>>a>>b;
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        ins(x,y);
        ins(y,x);
        s[x].insert(y);
        s[y].insert(x);
    }
    if(a==b){
        cout<<a;
    }
    else{
        long long ans1=bfs1();
        bfs2();
        long long ans2=bfs2();
        // cout<<ans1<<' '<<ans2<<endl;
        cout<<min(ans1*a,ans2*b);
    }
    
}