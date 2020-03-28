#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a%b==0){
            cout<<0<<endl;
            continue;
        }
        int div = a/b;
        div++;
        b*=div;
        cout<<b-a<<endl;
    }
    return 0;
}