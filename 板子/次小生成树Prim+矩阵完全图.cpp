#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f
#define MAX 1019
using namespace std;
double Map[MAX][MAX], dis[MAX], maxn[MAX][MAX]; 
int pre[MAX], vis[MAX];
bool used[MAX][MAX];
int n;
struct Edge
{
    double x, y, p;
}edge[MAX];
double cal(Edge a, Edge b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double prim()
{
    double ret = 0, minn;
    int father;
    memset(vis, 0, sizeof(vis));
    memset(maxn, 0, sizeof(maxn)); 
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; i++)
    {
        dis[i] = Map[1][i];
        pre[i] = 1;
    }
    vis[1] = 1;
    int k;
    for(int i = 1; i < n; i++)
    {
        minn = INF;
        for(int j = 1; j <= n; j++)//找离已访问点集最近的点 
        {
            if(!vis[j]&&dis[j] < minn)
            {
                minn = dis[j];
                k = j;
            }
        }
        if(minn == INF) return -1;
        vis[k] = 1;
        ret+=minn;
        father = pre[k];
        used[father][k] = used[k][father] = 1;//表示该边已在次小生成树中 
        maxn[father][k] = minn;
        for(int j = 1; j <= n; j++)
        {
            if(vis[j]&&j!=k)
                maxn[j][k] = maxn[k][j] = max(maxn[j][father], maxn[father][k]);//最小生成树中i j路径上的最长边
            
            if(!vis[j]&&dis[j] > Map[k][j])
            {
                dis[j] = Map[k][j];
                pre[j] = k;
            }
        }
    }
    return ret;
}
int main()//矩阵完全图 
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                Map[i][j] = INF;
            }
            Map[i][i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf",&edge[i].x, &edge[i].y, &edge[i].p);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                Map[i][j] = Map[j][i] = cal(edge[i], edge[j]);
            }
        }
        double ans = prim();
        printf("%.2lf\n",ans);
    }
    return 0;
}
