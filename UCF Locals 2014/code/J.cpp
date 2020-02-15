#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxl=2505;
const double esp=1e-6;
double arr[maxl];
void init()
{
    memset(arr,0,sizeof(arr));
    for(int i=1; i<=2505; i++)
    {
        arr[i]=arr[i-1]+log(i);
    }
}
double solve(int n)
{
    double sum=0;
    int p;
    for(int i=1; i<=n; i++)
    {
        cin>>p;
        sum+=arr[p];
    }
    return sum;
}
int main()
{
    int kas=1;
    int t;
    init();
    cin>>t;
    int a,b,c;
    while(t--)
    {
        cin>>a>>b>>c;
        double sum1=solve(a);
        double sum2=solve(b);
        double sum3=solve(c);
        cout<<"Case #"<<kas++<<": ";
        if(sum1-sum2>esp&&sum1-sum3>esp) cout<<'A'<<endl;
        else if(sum2-esp>sum1&&sum2-sum3>esp) cout<<'B'<<endl;
        else if(sum3-sum1>esp&&sum3-sum2>esp) cout<<'C'<<endl;
        else cout<<"TIE"<<endl;
    }
    return 0;
}
