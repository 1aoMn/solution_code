void spfa(int x,int n)
{
	queue<int>q;
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=e[i].nex)
		{
			int v=e[i].to;
			{
				if(dis[v]>dis[x]+e[i].val)
				{
					dis[v]=dis[x]+e[i].val;
					if(!vis[v])
					{
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
}
