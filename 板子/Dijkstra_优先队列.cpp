#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define PII pair<int,int>
#define N 1005
using namespace std;
struct edge
{
	int to,v,nex;
}e[N*N];
int head[N],s,dis[N];
int n,m;
void ins(int x,int y,int z)
{
	e[++s].nex=head[x];
	e[s].to=y;
	e[s].v=z;
	head[x]=s;
}
int dijkstra()
{
	memset(dis,127/3,sizeof(dis));
	dis[n]=0;
	priority_queue<PII , vector<PII> , greater<PII> >q;
	q.push(make_pair(0,n));
	while(!q.empty())
	{
		PII now=q.top();
		int x=now.second;
		q.pop();
		for(int i=head[x];i;i=e[i].nex)
		if(dis[e[i].to]>dis[x]+e[i].v)
		{
			dis[e[i].to]=dis[x]+e[i].v;
			q.push(make_pair(dis[e[i].to] , e[i].to));
		}
	}
	return dis[1];
}
int main()
{
	while(cin>>m>>n)
	{
		s=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			ins(x,y,z),ins(y,x,z);
		}
		cout<<dijkstra();
	}
	return 0;
}
