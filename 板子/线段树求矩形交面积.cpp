#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct data
{
    double x1,x2,y;
    int flag;
    }a[800001];
double has[200001];
double sum[800001];
double len1[800001];//区间被覆盖>=1次的线段长度 
double len2[800001];//>=2 
int col[800001];//区间被覆盖的次数 
inline bool cp(data a,data b){return a.y<b.y;}
void pushup(int size,int l,int r)
{
	if(col[size])
	{
		sum[size]=has[r+1]-has[l];
		if(col[size]>=2)
			len1[size]=len2[size]=sum[size];
		else if(col[size]==1)
			len1[size]=sum[size] , len2[size]=len1[size*2]+len1[size*2+1];
	}
	else
	{
		if(l==r)
			sum[size]=0;
		len1[size]=len1[size*2]+len1[size*2+1] , len2[size]=len2[size*2]+len2[size*2+1];
		sum[size]=sum[size*2]+sum[size*2+1];
	}
	
    /*
	if(col[size])sum[size]=has[r+1]-has[l];//col维护区间是否有线段覆盖  该区间被覆盖则返回X长度 
    else if(l==r)sum[size]=0;
    else sum[size]=sum[size*2]+sum[size*2+1];//该区间没被覆盖 则向上传递 
	*/
}
void update(int L,int R,int flag,int l,int r,int size)
{
    if(L<=l&&R>=r)
    {
        col[size]+=flag;//区间被覆盖 
        pushup(size,l,r);
        return;
    }
    int m=(l+r)/2;
    if(L<=m)update(L,R,flag,l,m,size*2);
    if(R>m)update(L,R,flag,m+1,r,size*2+1);
    pushup(size,l,r);
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
    	scanf("%d",&n);
	    double x1,y1,x2,y2;
	    for(int i=1;i<=n;i++)
	    {
	        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	        a[2*i-1].x1=a[2*i].x1=x1;
	        a[2*i-1].x2=a[2*i].x2=x2;
	        a[2*i-1].y=y1;a[2*i].y=y2;
	        a[2*i-1].flag=1;a[2*i].flag=-1;
	        has[2*i-1]=x1;has[2*i]=x2;
	    }
	    sort(a+1,a+2*n+1,cp);sort(has+1,has+2*n+1);
	    memset(col,0,sizeof(col));
	    memset(sum,0,sizeof(sum));
	    memset(len1,0,sizeof(len1));
	    memset(len2,0,sizeof(len2));
	    double ans=0;
	    for(int i=1;i<=2*n;i++)
	    {
	        int l=lower_bound(has+1,has+2*n+1,a[i].x1)-has;
	        int r=lower_bound(has+1,has+2*n+1,a[i].x2)-has-1;
	        if(l<=r)update(l,r,a[i].flag,1,2*n,1);
	        ans+=len2[1]*(a[i+1].y-a[i].y);
	        //cout<<len2[1]<<endl;
	    }
	    printf("%.2lf\n",ans);
	}
    return 0;
}
