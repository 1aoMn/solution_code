#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300;
const int maxd=450;

ll C[maxn][maxn];

int lucky[]={4,7,44,47,74,77,444};//ָ�����Ƕ���λ
set<int> fluck;//����λ��
ll arracum[7];
char ans[maxd];
int lans;

void Process(ll k){
    lans=0;
    int id=lower_bound(arracum,arracum+7,k)-arracum;//�ҵ�k���ڵڼ������
    int inim=1;
    int manyc=0,manys=0;//manycָ��4�ĸ�����manysָ��7�ĸ���
    if(id==7){//k��444�����
        lans=444;
        for(int i=1;i<=157;i++){
            ans[i]=ans[lans-(i-1)]='4';//1-157λ��288-444λ����'4'
        }
        inim = 158;
        manyc = 157;
    }
    else{
        lans=lucky[id-1];
    }
    
    int lim=lans/2;//ȡ�û��Ĵ���һ��
    ll curracum=arracum[id-1];//ȡ��k���ڵ�����µ�ǰ�漸������ĺ�
    for(int i=inim;i<=lim;i++){
        ll sum=0;
        for(int j=id-1;j>=0;j--){
            int hav=(lim-i);//���е�ľ���
            if((lans & 1)||(!(lucky[j]&1))){//���Ĵ��ĳ���Ϊ�������ߴ˿�j�׶������Ļ��Ĵ��ĳ���Ϊż��
                int pla = ((lucky[j]/2)-manyc-1);//����4��7���ֵĴ���������һ�����������֣����Գ��Ȳ���ǰ��Ľ׶εĳ���
                if((pla<=hav)&&(pla>=0)){//�����ʱ������Ϊ44�������ʹ��4�����������չ
                    sum+=C[hav][pla];//��hav�����з���pla���ִ�����'4'��'7'
                }

                pla = ((lucky[j]/2)-manys);//���ϴ�����
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
            C[i][j]=C[i-1][j-1]+C[i-1][j];//�����
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
        //sumָ������ÿ���׶εĻ��Ĵ��ĸ���
        acum+=sum;
        arracum[i+1]=acum;//arracum�����ÿ���׶εĿ�ʼֵ
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

