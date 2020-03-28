#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[50005],b[50005],c[50005];
int main(){
    int t,n;
    cin>>t;
    while(t--){
        char maxx='n',s[50005];
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)
            c[i+1]=s[i]-'0';
        a[1]=b[1]=1;
        for(int i=2;i<=n;i++){
            if(c[i]==0){
                a[i]=b[i]=0;
            } else if(c[i]==1){
                if(maxx=='b'){
                    a[i]=1;
                    b[i]=0;
                } else {
                    a[i]=0;
                    b[i]=1;
                    maxx = 'b';
                }
            } else if(c[i]==2){
                if(maxx=='n'){
                    a[i]=b[i]=1;
                } else if(maxx=='b'){
                    a[i]=2;b[i]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<a[i];
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<b[i];
        cout<<endl;
    }
    return 0;
}