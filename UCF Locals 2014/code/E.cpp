#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define N 115
using namespace std;
int n0,n,cnt;
int G0[N][N], G[N][N], in[N];
bool vis[N];
string name[N];
//ÖØÐÂ¹¹Í¼
void dfs(int u)
{
    vis[u] = 1;
    for (int i = 1; i <= n0; i++)
    {
        if (G0[u][i])
        {
            G[u][i] = 1;
            n++;
            in[i]++;
            if (!vis[i])
                dfs(i);
        }
    }
}
queue<int> q;
void top_sort()
{
    for (int i = 1; i <= n0; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cnt++;
        for (int i = 1; i <= n0; i++)
        {
            if (G[now][i])
            {
                in[i]--;
                if (in[i] == 0)
                    q.push(i);
            }
        }
    }
}
int main()
{
    int q, t, y, st, kase = 1;
    cin >> q;
    while (q--)
    {
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(G0,0,sizeof(G0));
        memset(in,0,sizeof(in));
        cnt=0;
        cin >> n0 >> st;
        for (int i = 1; i <= n0; i++)
            cin >> name[i];
        for (int i = 1; i <= n0; i++)
        {
            cin >> t;
            while (t--)
            {
                cin >> y;
                G0[i][y] = 1;
            }
        }
        dfs(st);
        top_sort();
        cout << "Chain Email #" << kase++ << ":\n";
        if(cnt==n0){
            cout<<"Safe chain email!\n";
        }
        else{
            for(int i=1;i<=n0;i++){
                if(in[i]!=0 && vis[i]){
                    cout<<name[i]<<' ';
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
