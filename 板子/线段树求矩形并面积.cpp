#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1) 
using namespace std;
double has[201],sum[804],cover[804];
struct data
{
	double X1,X2,Y;
	int flag;
}a[1000];
void pushup(int rt,int l,int r)
{
	if(cover[rt])//ÊÇ·ñÓĞÏß¶Î¸²¸Ç 
		sum[rt]=has[r+1]-has[l];
	else if(l==r)
	{
		sum[rt]=0;
		return ;
	} 
	else sum[rt]=sum[lson]+sum[rson];
}
void update(int rt,int l,int r,int L,int R,int v)
{
	if(L<=l && R>=r)
	{
		cover[rt]+=v;
		pushup(rt,l,r);
		return ;
	}
	if(L<=mid)
		update(lson,l,mid,L,R,v);
	if(R>mid)
		update(rson,mid+1,r,L,R,v);
	pushup(rt,l,r);
}
inline bool cp(data a,data b){return a.Y<b.Y;}
int main()
{
	//freopen("a.txt","w",stdout);
	int n,kase=1,t=0;
	while(cin>>n&&n)
	{
		double X1,X2,Y1,Y2;
		for(int i=1;i<=n;i++)
    	{
	        scanf("%lf %lf %lf %lf",&X1,&Y1,&X2,&Y2);
			a[2*i-1].X1=a[2*i].X1=X1;
	        a[2*i-1].X2=a[2*i].X2=X2;
	        a[2*i-1].Y=Y1;a[2*i].Y=Y2;
	        a[2*i-1].flag=1;a[2*i].flag=-1;
	        has[2*i-1]=X1;has[2*i]=X2;
	    }
		sort(a+1,a+2*n+1,cp);sort(has+1,has+2*n+1);
	    memset(cover,0,sizeof(cover));
	    memset(sum,0,sizeof(sum));
	    double ans=0;
	    for(int i=1;i<=2*n;i++)
	    {
	        int l=lower_bound(has+1,has+2*n+1,a[i].X1)-has;
	        int r=lower_bound(has+1,has+2*n+1,a[i].X2)-has-1;
	        if(l<=r)update(1,1,2*n,l,r,a[i].flag);
	        ans+=sum[1]*(a[i+1].Y-a[i].Y);
	    }
	    printf("Test case #%d\n",kase++);
	    printf("Total explored area: %.2lf\n\n",ans);
	}
    return 0;
}
