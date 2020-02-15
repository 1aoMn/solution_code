#include<iostream>
#include<cstdio>
#include<cstring>
#include<limits.h>
#define N 80000
#define ll long long
using namespace std;
struct edge
{
	int x,y,len;
	ll cost;
}e[N];
ll in[N];
int pre[N],vis[N],id[N];
ll zhuliu(int root,int n,int m)
{
	ll sum=0;
	while(true)
	{
		for(int i=0;i<n;i++)
			in[i]=LONG_LONG_MAX;
		for(int i=0;i<m;i++)
		{
			int x=e[i].x,y=e[i].y;
			if(e[i].cost<in[y]&&x!=y)
				in[y]=e[i].cost , pre[y]=x;
		}
		for(int i=0;i<n;i++)
		{
			//cout<<in[i]<<endl;
			if(i==root)
				continue;
			if(in[i]==LONG_LONG_MAX)
				return -1;
		}
		int circnt=0;
		memset(id,-1,sizeof(id));//id[i]表示i所属环 
		memset(vis,-1,sizeof(vis));//vis[i]把i标记为所在环有入度的那个点 
		in[root]=0;
		for(int i=0;i<n;i++)
		{
			sum+=in[i];
			int v=i;
			while(vis[v]!=i&&id[v]==-1&&v!=root)//找环 
			{
				vis[v]=i;
				v=pre[v];
			}
			if(v!=root&&id[v]==-1)//标记环 
			{
				for(int u=pre[v];u!=v;u=pre[u])
					id[u]=circnt;
					
				id[v] = circnt++;
			}
		}
		if(circnt==0)
			break;
		for(int i=0;i<n;i++)
			if(id[i]==-1)
				id[i]=circnt++;
		//缩点
		for(int i=0;i<m;i++) 
		{
			int v=e[i].y;
			e[i].x=id[e[i].x];
			e[i].y=id[e[i].y];
			if(e[i].x!=e[i].y)
				e[i].cost-=in[v];
		}
		root=id[root];
		n=circnt;
	}
	return sum;
}
int n,m,x[N],y[N];
ll C,c[N],d[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d %lld" , &n,&m,&C);
		ll l=1,r=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %lld %lld",x+i,y+i,d+i,c+i);
			r=max(r,d[i]);
		}
		r++;
		while(l<r)
		{
			ll mid=l+(r-l)/2;
			int edgnum=0;
			for(int i=0;i<m;i++)
				if(d[i]>=mid)
					e[edgnum].x=x[i],e[edgnum].y=y[i],e[edgnum++].cost=c[i];
			ll ans=zhuliu(0,n,edgnum);
			//cout<<ans<<endl;
			if(ans==-1||ans>C)
				r=mid;
			else l=mid+1;
		}
		if(l==1)
			puts("streaming not possible.");
        else printf("%lld kbps\n",l-1);
			
	}
	return 0;
}
