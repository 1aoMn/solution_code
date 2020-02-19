#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300;
const int maxd=450;

ll C[maxn][maxn];

int lucky[]={4,7,44,47,74,77,444};//指代的是多少位
set<int> fluck;//存入位数
ll arracum[7];
char ans[maxd];
int lans;

void Process(ll k){
    lans=0;
    int id=lower_bound(arracum,arracum+7,k)-arracum;//找到k是在第几种情况
    int inim=1;
    int manyc=0,manys=0;//manyc指代4的个数，manys指代7的个数
    if(id==7){//k在444情况中
        lans=444;
        for(int i=1;i<=157;i++){
            ans[i]=ans[lans-(i-1)]='4';//1-157位，288-444位都是'4'
        }
        inim = 158;
        manyc = 157;
    }
    else{
        lans=lucky[id-1];
    }
    
    int lim=lans/2;//取得回文串的一半
    ll curracum=arracum[id-1];//取得k所在的情况下的前面几次情况的和
    for(int i=inim;i<=lim;i++){
        ll sum=0;
        for(int j=id-1;j>=0;j--){
            int hav=(lim-i);//与中点的距离
            if((lans & 1)||(!(lucky[j]&1))){//回文串的长度为奇数或者此刻j阶段所处的回文串的长度为偶数
                int pla = ((lucky[j]/2)-manyc-1);//由于4，7出现的次数至少有一个是幸运数字，所以长度采用前面的阶段的长度
                if((pla<=hav)&&(pla>=0)){//例如此时长度若为44，则可以使用4这个长度来扩展
                    sum+=C[hav][pla];//在hav长度中分配pla出现次数的'4'或'7'
                }

                pla = ((lucky[j]/2)-manys);//与上处类似
                if((pla<=hav)&&(pla>=0)){
                    sum+=C[hav][pla];
                }
            }
        }

        if(curracum + sum >= k){
            ans[i] = ans[lans - (i - 1)]='4';
            manyc++;
        }
        else{
            curracum += sum;
            ans[i] = ans[lans- (i - 1)]='7';
            manys++;
        }
    }
    manyc <<= 1;
    manys <<= 1;
    if(lans & 1){
        if(fluck.find(manyc) != fluck.end()){
            ans[(lans/2)+1] = '7';
            manys++;
        }else if(fluck.find(manys) != fluck.end()){
            ans[(lans/2)+1] = '4';
            manyc++;
        }else if(fluck.find(manyc+1) != fluck.end()){
            ans[(lans/2)+1] = '4';
            manyc++;
        }else{
            ans[(lans/2)+1] = '7';
            manys++;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    fluck.insert(4);
    fluck.insert(7);
    fluck.insert(44);
    fluck.insert(47);
    fluck.insert(74);
    fluck.insert(77);
    fluck.insert(444);

    C[0][0]=1LL;
    for(int i=1;i<maxn;i++){
        C[i][0]=1LL;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];//组合数
        }
    }
    ll acum=0;
    for(int i=0;i<6;i++){
        int len=lucky[i];
        //cout<<len<<endl;
        ll sum=0;
        for(int j=i;j>=0;j--){
            int manyn=lucky[j];
            if((len&1)||(!(manyn&1))){
                sum+=(C[len/2][manyn/2])*2LL;    
            }
        }
        //cout<<sum<<endl;
        //sum指代的是每个阶段的回文串的个数
        acum+=sum;
        arracum[i+1]=acum;//arracum存的是每个阶段的开始值
    }
    int T;
    ll k;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>k;
        Process(k);
        cout<<"Query #"<<i<<": ";
        for(int j=1;j<=lans;j++){
            cout<<ans[j];
        }
        cout<<endl;
    }
    getchar();
    getchar();
    return 0;
}

