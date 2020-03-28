#include<iostream>
using namespace std;
int main(){
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<a<<' '<<b<<' '<<c<<endl;
        int pd = (a>=10)+(b>=10)+(c>=10);
        if(pd==0){
            cout<<"zilch\n\n";
        } else if(pd==1){
            cout<<"double\n\n";
        } else if(pd==2){
            cout<<"double-double\n\n";
        } else cout<<"triple-double\n\n";
    }
    return 0;
}