#include<cstdio>
#include<iostream>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1) 
using namespace std;
int tree[400005],lazy[400005];
void pushup(int rt)
{
	tree[rt]=tree[lson]+tree[rson];
}
void pushdown(int rt,int m)
{
	if(lazy[rt])
	{
		lazy[lson]=lazy[rson]=lazy[rt];
		tree[lson]=(m-(m>>1))*lazy[rt];
		tree[rson]=(m>>1)*lazy[rt];
		lazy[rt]=0;
	}
}
void build_tree(int rt,int l,int r)
{
	if(l==r)
	{
		tree[rt]=1;
		return ;
	}
	build_tree(lson,l,mid);
	build_tree(rson,mid+1,r) ;
	pushup(rt);
}
void update(int rt,int l,int r,int L,int R,int v)
{
	if(L<=l && R>=r)
	{
		tree[rt]=(r-l+1)*v;
		lazy[rt]=v;
		return ;
	}
	pushdown(rt,r-l+1);
	if(L<=mid)
		update(lson,l,mid,L,R,v);
	if(R>mid)
		update(rson,mid+1,r,L,R,v);
	pushup(rt);
}
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
         if(ch=='-')f=-1;
         ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
         x=(x<<3)+(x<<1)+ch-'0';
         ch=getchar();
    }
    return x*f;
}
int main()
{
	int t,n,x,y,z,q;
	t=read();
	for(int kase=1;kase<=t;kase++)
	{
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		n=read();
		build_tree(1,1,n);
		q=read();
		for(int i=1;i<=q;i++)
		{
			x=read();y=read();z=read();
			update(1,1,n,x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",kase,tree[1]);
	}
	return 0;
} 
