#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
#define maxn 1100
#define inf 0x3f3f3f3f
using namespace std;
int n, m;
int value[maxn][maxn];
int x[maxn],y[maxn];
int dis[maxn];
int pre[maxn];
bool vis[maxn];
void dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for(int i=1; i<=n; i++) dis[i] = value[s][i];
    for(int i=1; i<n; i++) {
        int p;
        int mindis = -1;
        for(int j=1; j<=n; j++) {
            if(!vis[j] && dis[j]>mindis)
                mindis = dis[p=j];
        }
        vis[p] = 1;
        for(int j=1; j<=n; j++) {
            if(!vis[j] && dis[j] < min(dis[p],value[p][j])) {
                dis[j] = min(dis[p], value[p][j]);
                pre[j] = p;
            }
        }
    }
}
int main()
{
    int t,ca=1; cin>>t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) value[i][j]=0;
        while(m--){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
            value[u][v] = value[v][u] = w;
        }
        dijkstra(1);
        printf("Scenario #%d:\n%d\n\n", ca++, dis[n]);
    }
    return 0;
}
/*
1
7 7
1 3 5
2 7 3
1 4 4
2 5 8
3 6 4
1 3 6
5 6 3
*/
