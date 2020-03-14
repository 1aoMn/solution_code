#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        ans+=i-n;
    }
    cout<<ans;
    return 0;
}