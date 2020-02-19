#include<iostream>
using namespace std;
int veryclear[100000],ce_clear[100000],unclear[100000];
int sum[100000];
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>veryclear[i]>>ce_clear[i]>>unclear[i];
        sum[i]=veryclear[i]*2+ce_clear[i];
    }
    for(int i=0;i<t;i++){
        int ans;
        if(ce_clear[i]==0){
            if(unclear[i]==0){
                ans=(sum[i]==0)?sum[i]:sum[i]/2+1;
            }
            else{
                ans=sum[i]/2;
            }
            
        }
        else{
            ans=sum[i]/2+1;
        }
        cout<<"Scenario #"<<i+1<<": "<<ans<<endl;
    }
    return 0;
}

