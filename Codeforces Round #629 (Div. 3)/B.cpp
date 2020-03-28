#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("B.txt","w",stdout);
    long long t,n;
    double k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long num = (1+int(sqrt(8.0*k)))/2;
        int timea1 = n-1-num;
        int timea2 = num*(num+1)/2-(int)k;
        int timea3 = (int)k-num*(num-1)/2-1;
        for(int i=1;i<=timea1;i++)
            printf("a");
        cout<<'b';
        for(int i=1;i<=timea2;i++)
            printf("a");
        cout<<'b';
        for(int i=1;i<=timea3;i++)
            printf("a");
        cout<<endl;
        
    }
    return 0;
}