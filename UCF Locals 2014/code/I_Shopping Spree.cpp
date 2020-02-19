#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t,n,kase=0,a[505],dp[505][505];
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(n==1){
			cout<<"Spree #"<<++kase<<": "<<a[0]<<endl;
			continue;
		}
		dp[0][1]=a[0];
		for(int i=1;i<n;i++){
			for(int j=1;j<=max(1,(i+1)/2);j++){
				dp[i][j] = max(dp[i][j-1] , max(dp[i-1][j] , dp[i-1][j-1]+a[i]));
				cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<"Spree #"<<++kase<<": "<<dp[n-1][n/2]<<endl;
	}
	return 0;
}
