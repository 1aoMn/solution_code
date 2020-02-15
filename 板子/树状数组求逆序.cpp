#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int tr[1000005],n;
struct dat
{
	int id,x;
}a[500005];
int lowbit(int x)
{
	return x&-x;
} 
void upd(int x,int y)
{
	while(x<=n)
	{
		tr[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int sum=0;
	while(x)
	{
		sum+=tr[x];
		x-=lowbit(x);
	}
	return sum;
}
bool cmp(dat a,dat b)
{
	return a.x<b.x;
}
int main()
{
	while(cin>>n&&n)
	{
		long long ans=0;
		memset(tr,0,sizeof(tr));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x;
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			upd(a[i].id,1);
			ans+=(long long)i-(long long)query(a[i].id);
		}
		cout<<ans<<endl;
	}
} 
/*
5
9 1 0 5 4
3
1 2 3

8
7 5 9 4 8 2 5 3   
*/
