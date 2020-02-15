#include <stdio.h>
#include <string.h>
#define MaxInt 0x3f3f3f3f
#define N 110
int map[N][N],low[N],visited[N];
int n;
 
int prim()
{
    int i,j,pos,min,result=0;
    memset(visited,0,sizeof(visited));
    visited[1]=1;pos=1;
    for(i=1;i<=n;i++)
        if(i!=pos) low[i]=map[pos][i];
    for(i=1;i<n;i++)
    {
     min=MaxInt;
     for(j=1;j<=n;j++)
         if(visited[j]==0&&min>low[j])
         {
             min=low[j];pos=j;
         }
    result+=min;
    visited[pos]=1;
    for(j=1;j<=n;j++)
        if(visited[j]==0&&low[j]>map[pos][j])
            low[j]=map[pos][j];
    }
    return result;
}
 
int main()
{
    int i,v,j,ans;
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,MaxInt,sizeof(map));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&v);
                map[i][j]=map[i][j]=v;
            }
            ans=prim();
            printf("%d\n",ans);
    }
    return 0;
}
