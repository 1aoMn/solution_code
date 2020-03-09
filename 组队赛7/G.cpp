#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
#define N 100005
using namespace std;
const int H = 150000;
int n,rmq[20][N],flag[N],L[N],R[N],a[N],lg[N];
void init(){
    for(int i=2;i<N;i++)
        lg[i]=lg[i>>1]+1;
    for(int i=1;i<20;i++)
        for(int j=1;j<=n-(1<<i)+1;j++)
            rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
}
int query(int l,int r){
    int k=lg[r-l+1];
    return min(rmq[k][l],rmq[k][r-(1<<k)+1]);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            rmq[0][i]=a[i];
        }
        a[0]=a[n+1]=0x3f3f3f3f;
        init();

        stack<int>st;
        st.push(0);
        for(int i=1;i<=n;i++){
            while(!st.empty() && a[st.top()]<=a[i]){
                st.pop();
            }
            if(!st.empty())
                L[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        st.push(n+1);
        for(int i=n;i>=1;i--){
            while(!st.empty() && a[st.top()]<=a[i])
                st.pop();
            if(!st.empty())
                R[i]=st.top();
            st.push(i);
        }

        for(int i=1;i<=n;i++){
            int t=-1;
            if(L[i]!=0)
                t=max(query(L[i],i),t);
            if(R[i]!=n+1)
                t=max(query(i,R[i]),t);
            if(t==-1)
                flag[i]=1;
            else if(a[i]-t>=H)
                flag[i]=1;
        }
        for(int i=1;i<=n;i++){
            if(flag[i])
                cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}
/*
26
0 50000 150000 200000 150000 200000 300000 
100000 50000 150000 330000 350000 250000 
350000 200000 220000 300000 50000 100000 
250000 100000 150000 500000 300000 250000 0
*/
