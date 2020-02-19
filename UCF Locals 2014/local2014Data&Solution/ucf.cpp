#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500+10;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll pasc[MAXN][MAXN];
int isleaf[MAXN];
int isbranch[MAXN];
int deg[MAXN];
int vis[MAXN];
vector<int> adj[MAXN];

struct P{
    int size;
    ll ways;
};
P go(int i,int p)
{
    int size=0;
    ll ways=1;
    for(int j=0;j<adj[i].size();j++){
        int temp=adj[i][j];
        if(temp==p||isbranch[temp]==0) continue;
        P rr=go(temp,i);
        ways=(ways*rr.ways)%MOD;
        ways=(ways*pasc[rr.size][size])%MOD;
        cout<<i+1<<'-'<<1+temp<<' '<<rr.size<<' '<<size<<' '<<pasc[rr.size][size]<<' '<<rr.ways<<' '<<ways<<endl;
        size+=rr.size;
    }
    P t;
    t.size=size+1,t.ways=ways;
    return t;
}
int main()
{
//    freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);
    int t,kase=0;
    int n,m;
    pasc[0][0]=1;
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            pasc[i+1][j]=(pasc[i+1][j]+pasc[i][j])%MOD;
            pasc[i][j+1]=(pasc[i][j+1]+pasc[i][j])%MOD;
        }
    }
    for(int i=0;i<=5;i++){
    	for(int j=0;j<=5;j++)
    		cout<<pasc[i][j]<<' ';
    	cout<<endl;
	}
    cin>>t;
    while(t--){
        cin>>n>>m;
        int cost[MAXN];
        for(int i=0;i<n;i++)
            cin>>cost[i];
        memset(isleaf,0,sizeof(isleaf));
        memset(isbranch,0,sizeof(isbranch));
        int numedges=m;
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        while(m>0){
            int i,j;
            cin>>i>>j;
            adj[i-1].push_back(j-1);
            adj[j-1].push_back(i-1);
            m--;
        }
        for(int i=0;i<n;i++)
            if(adj[i].size()==1) isleaf[i]=1;
        int minsize=-1,mincost=-1;
        ll numways=-1;
        if(numedges==1){ 
            minsize=1;
            mincost=min(cost[0],cost[1]);
            if(cost[0]==cost[1]) numways=2;
            else numways=1;
        }else if(numedges==n-1){//ÊÇÒ»¿ÃÊ÷ 
            minsize=1;
            mincost=0;
            numways=0;
            for(int i=0;i<n;i++)
                if(!isleaf[i]) isbranch[i]=1;
            for(int i=0;i<n;i++)
                if(isbranch[i]) mincost+=cost[i];
            for(int i=0;i<n;i++){
                if(isbranch[i]){
                	int tmp = go(i,i).ways; 
                    numways+=tmp;
                    numways%=MOD;
                    cout<<endl<<tmp<<endl;
                }
            }
        }else{
            memset(deg,0,sizeof(deg));
            memset(vis,0,sizeof(vis));
            queue<int> q;
            for(int i=0;i<n;i++){
                if(isleaf[i]) q.push(i);
                else deg[i]=adj[i].size();
            }
            memset(vis,0,sizeof(vis));
            while(!q.empty()){
                int i=q.front();
                q.pop();
                for(int j=0;j<adj[i].size();j++){
                    int temp=adj[i][j];
                    if(deg[temp]>1){
                        deg[temp]--;
                        vis[temp]=1;
                        if(deg[temp]==1) q.push(temp);
                    }
                }
                if(!isleaf[i]) isbranch[i]=1;
            }
            vector<int> roots;
            for(int i=0;i<n;i++)
                if(!isleaf[i]&&!isbranch[i]&&vis[i]) roots.push_back(i);
            minsize=n;
            mincost=0;
            for(int i=0;i<n;i++)
                if(isbranch[i]) mincost+=cost[i];
            for(int i=0;i<n;i++)
                if(isbranch[i]||isleaf[i]) minsize--;
            int size=0;
            numways=1;
            for(int i=0;i<roots.size();i++){
                int r=roots[i];
                P rr=go(r,r);
                numways=(numways*rr.ways)%MOD;
                numways=(numways*pasc[size][rr.size])%MOD;
                mincost+=cost[r];
                size+=rr.size;
            }
        }
        cout<<"Case #"<<++kase<<": ";
        cout<<minsize<<" "<<mincost<<" "<<numways<<endl;
    }
    return 0;
}

