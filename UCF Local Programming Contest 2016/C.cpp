#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int row[100],col[100],a[100][100];
int main(){
    int t,n,moves,x,y,ans;
    cin>>t;
    for(int kase=1;kase<=t;kase++){
        cin>>n>>moves;
        ans=0;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(a,0,sizeof(a));
        for(int i=1;i<=moves;i++){
            cin>>x>>y;
            if(a[x][y] || row[x]&&col[y]){
                ans++;
                continue;
            }
            a[x][y]=1;
            row[x]++,col[y]++;
        }
        cout<<"Strategy #"<<kase<<": "<<ans<<endl<<endl;
    }
    return 0;
}