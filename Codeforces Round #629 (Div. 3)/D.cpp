#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[200005],k[200005],pk[4],m[200005];
int calc(int x){
    return x==1?2:1;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int f=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[1]) f=1;
        }
        if(!f){
            cout<<1<<endl;
            for(int i=1;i<=n;i++) cout<<1<<' ';
            cout<<endl;
        }
        else if(n%2==0){
            cout<<2<<endl;
            for(int i=1;i<=n;i++)
                cout<<(f^=1)+1<<' ';
            cout<<endl;
        } else{
            for(int i=1;i<=n;i++){
                if(a[i]==a[i%n+1]){
                    int ans[n+1];
                    for(int j=1,f=1;j<=i;j++,f^=1){
                        ans[j]=f+1;
                    }
                    for(int j=n,f=0;j>=i+1;j--,f^=1){
                        ans[j]=f+1;
                    }
                    cout<<2<<endl;
                    for(int j=1;j<=n;j++)
                        cout<<ans[j]<<' ';
                    cout<<endl;
                    goto A;
                }
            }

            cout<<3<<endl;
            for(int i=1,f=1;i<=n-1;i++,f^=1){
                cout<<f+1<<' ';
            }
            cout<<3<<endl;
        }
        A: ;
    }
    return 0;
}