#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int a[1000001],cnt[10000007];
int main(){
    int t,n;
    int maxx;
    ll ans;
    cin>>t;
    for(int kase=1;kase<=t;kase++){
        memset(cnt,0,sizeof(cnt));
        cout<<"Test case #"<<kase<<": ";
        maxx=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx=max(a[i],maxx);
            cnt[a[i]]++;
        }
        //i作为被除数
        ans+=(ll)(cnt[0])*(ll)((n-cnt[0]));
        //1
        ans+=(ll)(cnt[1])*(ll)(n-cnt[1]-cnt[0]);
        //i作为除数
        for(int i=2;i<=maxx/2;i++){
            if(cnt[i]){
                int tmp=0;
                for(int j=i*2;j<=maxx;j+=i){
                    if(cnt[j]){
                       tmp+=(ll)cnt[j]; 
                    }
                }
                ans+=(ll)tmp*(ll)cnt[i];
            }
        }
        cout<<ans<<endl<<endl;
    }
    return 0;
}