#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 800000
#define ll long long
using namespace std;

ll t1[MAXN], t2[MAXN];
int n,q;
ll x,y,z;

inline int lowbit(int x) { return x & (-x); }

void add(ll k, ll v) {
  ll v1 = k * v;
  while (k <= n) {
    t1[k] += v, t2[k] += v1;
    k += lowbit(k);
  }
}

ll getsum(ll k) {
  long long ret = 0;
  
  for(int i=k;i>0;i-=lowbit(i))
  {
  	
  	ret+=(k+1)*t1[i]-t2[i];
  }
  
  return ret;
}

void add1(int l, int r, ll v) {
  add(l, v), add(r + 1, -v);  //将区间加差分为两个前缀加
}

long long getsum1(int l, int r) {
	return getsum(r)-getsum(l-1);
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		add(i,x-y);
		y=x;
	}
	while(q--)
	{
		char op;
		cin>>op;
		scanf("%lld%lld",&x,&y);
		if(op=='Q')
			cout<<getsum1(x,y)<<endl;
		else
		{
			scanf("%lld",&z);
			add1(x,y,z);
		}
	}
	return 0;
}
