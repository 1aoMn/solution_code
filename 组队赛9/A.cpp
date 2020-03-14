#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
    int out,in,cost;
}a[1005];
int vis[1005];
bool cmp(point a,point b){
    return a.out>b.out;
}
int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].out,&a[i].in,&a[i].cost);
        ans+=a[i].in * a[i].cost;
    }
    int maxx,pos;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        maxx=pos=-1;
        for(int j=1;j<=n;j++){
            if(vis[j]) continue;
            if(maxx<a[j].cost*a[i].out && a[i].out<a[j].in){
                maxx = a[j].cost*a[i].out;
                pos=j;
            }
        }
        if(pos!=-1){
            ans-=maxx;
            vis[pos]=1;
        }
    }
    cout<<ans;
    return 0;
}