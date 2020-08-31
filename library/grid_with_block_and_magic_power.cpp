#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%ch",&ch)
#define ps(a) printf("%s",a)
#define newLine() printf("\n")
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define pd(a) printf("%lf",a)
#define pdd(a,b) printf("%lf %lf",a,b)
#define pddd(a,b,c) printf("%lf %lf %lf",a,b,c)
#define pch(c) printf("%ch",c)
#define debug1(str,a) printf("%s=%d\n",str,a)
#define debug2(str1,str2,a,b) printf("%s=%d %s=%d\n",str1,a,str2,b)
#define debug3(str1,str2,str3,a,b,c) printf("%s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c)
#define debug4(str1,str2,str3,str4,a,b,c,d) printf("%s=%d %s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c,str4,d)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define NL puts("")
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf %lf",&a,&b)
#define sddd(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define SP printf(" ")
#define LL long long int
#define ULL unsigned long long int
#define MOD 1000000007
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
#define eps 1e-9
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n  (1<<pos))
#define para(i,a,b,ara)\
for(i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    cout<<ara[i];\
}\
printf("\n");
#define pvec(i,vec)\
for(i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    cout<<vec[i];\
}\
printf("\n");
#define ppara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    for(j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        cout<<ara[i][j];\
    }\
    printf("\n");\
}
#define ppstructara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j];printf("\n");\
    }\
}
#define ppvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        cout<<vec[i][j];\
    }\
    printf("\n");\
}
#define ppstructvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j];printf("\n");\
    }\
}
#define sara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}
#define pstructara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i];NL;\
}
#define pstructvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i];NL;\
}
#define pstructstl(stl,x)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    x=*it;\
    cout<<x;NL;\
}\
NL;
#define pstl(stl)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    if(it!=stl.begin()){SP;}\
    pi(*it);\
}\
NL;
#define ppairvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i].first;SP;cout<<vec[i].second;printf("\n");\
}
#define ppairara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i].first;SP;cout<<ara[i].second;printf("\n");\
}
#define pppairvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;SP;cout<<vec[i][j].second;NL;\
    }\
}
#define pppairara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;NL;\
    }\
}
#define SZ 105
//std::ostream & dump(std::ostream &os)const{
//    return os<<"l="<<l
//             <<"r="<<r
//             <<"m="<<m;
//}
//std::ostream & operator<<(ostream &os,seg &s){
//    return s.dump(os);
//}
using namespace std;
//bool status[1010];
//vector <int> prime;
//void siv(){
//    int N=1005,i,j;prime.clear();
//    int sq=sqrt(N);
//    for(i=4;i<=N;i+=2){status[i]=1};
//    for(i=3;i<=sq;i+=2){
//        if(status[i]==0){
//            for(j=i*i;j<=N;j+=i){status[j]=1;}
//        }
//    }
//    status[1]=1;
//    for1(i,N){
//        if(!status[i]){prime.pub(i);}
//    }
//}
int n,m,toBlock,toPower;
int fac[1000010],inv[1000010],invFac[1000010];
int dpAtLeast[SZ][SZ],dpExact[SZ][SZ];
pair <int,int> ara[SZ];
inline int add(int _a,int _b){
    _a=(LL)((LL)_a+MOD)%MOD;
    _b=(LL)((LL)_b+MOD)%MOD;
    return (LL)((LL)_a+(LL)_b)%MOD;
}
inline int mul(int _a,int _b){
    _a=(LL)((LL)_a+MOD)%MOD;
    _b=(LL)((LL)_b+MOD)%MOD;
    return (LL)((LL)_a*(LL)_b)%MOD;
}
inline int gcdExtended(int _a,int _b,int *_x,int *_y){
    if(_a==0){
        *_x=0,*_y=1;
        return _b;
    }
    int _x1,_y1;
    int _gcd=gcdExtended(_b%_a,_a,&_x1,&_y1);
    *_x=_y1-(_b/_a)*_x1;
    *_y=_x1;
    return _gcd;
}
inline int modInverse(int _a,int _mod){
    int _x,_y;
    int _g=gcdExtended(_a,_mod,&_x,&_y);
        // m is added to handle negative x
    int _res=(_x%MOD+MOD)%MOD;
    return _res;
}
void pre(){
    int i,j;
    fac[0]=1;
    for1(i,1000000){
        fac[i]=mul(fac[i-1],i);
        inv[i]=modInverse(i,MOD);
    }
    invFac[0]=1;
    for1(i,1000000){
        invFac[i]=mul(invFac[i-1],inv[i]);
    }
}
bool cmp(pair <int,int> lhs, pair <int,int > rhs){
    if(lhs.first==rhs.first){
        return lhs.second<rhs.second;
    }
    return lhs.first<rhs.first;
}
void input(){
    int i,j;
    sii(n,m);
    sii(toBlock,toPower);
    for0(i,toBlock){
        sii(ara[i].first,ara[i].second);
        ara[i].first--;ara[i].second--;
    }
    sort(ara,ara+toBlock,cmp);
    ara[toBlock]=make_pair(n-1,m-1);toBlock++;
}
int totalPath(int x1,int y1,int x2,int y2){
    if(x1>x2||y1>y2){return 0;}
    int absX=abs(x2-x1);
    int absY=abs(y2-y1);
    int nnom=fac[absX+absY];
    int dnom=mul(invFac[absX],invFac[absY]);
    int s=mul(nnom,dnom);
    return s;
}
void solve(){
    int i,j,s,path,k,l;
    for0(i,toBlock){
        for0(k,toPower+1){
            dpAtLeast[i][k]=totalPath(0,0,ara[i].first,ara[i].second);
            for(j=0;j<i;j++){
                path=totalPath(ara[j].first,ara[j].second,ara[i].first,ara[i].second);
                s=mul(dpExact[j][k],path);
                dpAtLeast[i][k]=add(dpAtLeast[i][k],-s);
            }
        }
        for0(k,toPower+1){
            if(k==0){dpExact[i][k]=dpAtLeast[i][k];}
            else{
                dpExact[i][k]=add(dpAtLeast[i][k],-dpAtLeast[i][k-1]);
            }
        }
    }
    pi(dpAtLeast[toBlock-1][toPower]);NL;
}
int main(){
//    freopen("input.txt","r",stdin);
    int cs,ts;
    pre();
    si(ts);
    for0(cs,ts){
        input();
        solve();
    }
}
