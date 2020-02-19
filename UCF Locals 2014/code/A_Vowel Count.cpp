#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int n,len,cnt0,cnt1;
    char s[100];
    cin>>n;
    while(n--){
        cin>>s;
        cnt0=cnt1=0;
        len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                cnt0++;
            cnt1=len-cnt0;
        }
        cout<<s<<endl;;
        if(cnt0>cnt1)
            cout<<1;
        else cout<<0;
        cout<<endl;
    }
    return 0;
}
