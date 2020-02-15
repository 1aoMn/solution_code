#include<cstdio>
#include<iostream>
#include<cstring>
#define N 100005
using namespace std;
struct edge
{
	int to,nex;
}e[N*2];
struct node
{
	int id,num;
}nod[N];
int head[N],s,dfs_num,exist[N*2],tr[N*2];
int n,q,x,y;
void ins(int x,int y)
{
	e[++s].nex=head[x];
	e[s].to=y;
	head[x]=s;
}
int dfs(int x)
{
	nod[x].id=dfs_num;
	for(int i=head[x];i;i=e[i].nex)
	{
		dfs_num++;
		nod[x].num=dfs(e[i].to);
	}
	nod[x].num=dfs_num;
}
int lowb(int x)
{
	return x&-x;
}
void add(int x,int y)
{
	while(x)
	{
		tr[x]+=y;
		x-=lowb(x);
	}
}
int query(int x)
{
	int ans=0;
	while(x<=n)
	{
		ans+=tr[x];
		x+=lowb(x);
	}
	return ans;
}
int main()
{
	dfs_num=1;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		ins(x,y);
	}
	dfs(1);
	n=dfs_num;
	for(int i=1;i<=n;i++)
		add(i,1);
	cin>>q;
	char op;
	for(int i=1;i<=dfs_num;i++)
		exist[i]=1;
	while(q--)
	{
		getchar();
		scanf("%c %d",&op,&x);
		if(op=='Q')
			cout<<query(nod[x].id) - query(nod[x].num+1)<<endl;
		else
		{
			if(exist[x])
				add(nod[x].id , -1) , exist[x]=0;
			else
				add(nod[x].id , 1) , exist[x]=1;
		}
	}
	return 0;
}
/*
5
1 2
1 3
2 4
2 5
7
Q 1
C 1
Q 1
C 2
Q 2
C 4
Q 4
*/
