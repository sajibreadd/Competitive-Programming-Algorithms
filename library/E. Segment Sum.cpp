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
#define MOD 998244353
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
#define SZ 100010
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
LL l, r, k, dp1[20][(1<<10)+10][12][2], dp2[20][(1<<10)+10][12][2], P[25];
vector <LL> digit;
LL add(LL _a, LL _b){
    _a = (_a + MOD)%MOD;
    _b = (_b + MOD)%MOD;
    return (_a + _b)%MOD;
}
LL mul(LL _a, LL _b){
    _a = (_a + MOD)%MOD;
    _b = (_b + MOD)%MOD;
    return (_a * _b)%MOD;
}
void pre(){
    LL i, j;
    P[0] = 1;
    for1(i, 23){
        P[i] = mul(P[i - 1], 10);
    }
}
LL F2(LL pos, LL mask, LL taken, bool sFlag){
    if(pos == digit.size()){
        if(taken <= k){return 1LL;}
        else{return 0LL;}
    }
    if(dp2[pos][mask][taken][sFlag] != -1){
        return dp2[pos][mask][taken][sFlag];
    }
    LL s = 0, i, j, ret = 0;
    if(sFlag){
        for(i = 0; i <= min(digit[pos], 9LL); i++){
            if(i < digit[pos]){
                if(!(mask & (1LL << i))){
                    s = F2(pos + 1, mask | (1LL << i), taken + 1, false)%MOD;
                    ret = add(ret, s);
                }
                else{
                    s = F2(pos + 1, mask, taken, false)%MOD;
                    ret = add(ret, s);
                }
            }
            else if(i == digit[pos]){
                if(!(mask & (1LL << i))){
                    s = F2(pos + 1, mask | (1LL << i), taken + 1, true)%MOD;
                    ret = add(ret, s);
                }
                else{
                    s = F2(pos + 1, mask, taken, true)%MOD;
                    ret = add(ret, s);
                }
            }
        }
    }
    else{
        for(i = 0; i <= 9; i++){
            if(!(mask & (1LL << i))){
                s = F2(pos + 1, mask | (1LL << i), taken + 1, false)%MOD;
                ret = add(ret, s);
            }
            else{
                s = F2(pos + 1, mask, taken, false)%MOD;
                ret = add(ret, s);
            }
        }
    }
    return dp2[pos][mask][taken][sFlag] = ret;
}
LL F1(LL pos, LL mask, LL taken, bool sFlag, bool shuru){
    if(pos == digit.size()){return 0LL;}
    if(dp1[pos][mask][taken][sFlag] != -1){
        return dp1[pos][mask][taken][sFlag];
    }
    LL s = 0, i, j, ret = 0, v, u, sz = digit.size();
    if(sFlag){
        for(i = 0; i <= digit[pos]; i++){
            if(i == 0 && shuru){
                v = F2(pos + 1, mask, taken, false)%MOD;
                u = mul(i, P[sz - pos - 1]);
                u = mul(u, v);
                s = F1(pos + 1, mask, taken, false, true)%MOD;
                s = add(s, u);
                ret = add(ret, s);
            }
            else if(i < digit[pos]){
                if(!(mask & (1LL << i))){
                    v = F2(pos + 1, mask | (1LL << i), taken + 1, false)%MOD;
                    u = mul(i, P[sz - pos - 1]);
                    u = mul(u, v);
                    s = F1(pos + 1, mask | (1LL << i), taken + 1, false, false)%MOD;
                    s = add(s, u);
                    ret = add(ret, s);
                }
                else{
                    v = F2(pos + 1, mask, taken, false)%MOD;
                    u = mul(i, P[sz - pos - 1]);
                    u = mul(u, v);
                    s = F1(pos + 1, mask, taken, false, false)%MOD;
                    s = add(s, u);
                    ret = add(ret, s);
                }
            }
            else{
                if(!(mask & (1LL << i))){
                    v = F2(pos + 1, mask | (1LL << i), taken + 1, true)%MOD;
                    u = mul(i, P[sz - pos - 1]);
                    u = mul(u, v);
                    s = F1(pos + 1, mask | (1LL << i), taken + 1, true, false)%MOD;
                    s = add(s, u);
                    ret = add(ret, s);
                }
                else{
                    v = F2(pos + 1, mask, taken, true)%MOD;
                    u = mul(i, P[sz - pos - 1]);
                    u = mul(u, v);
                    s = F1(pos + 1, mask, taken, true, false)%MOD;
                    s = add(s, u);
                    ret = add(ret, s);
                }
            }
        }
    }
    else{
        for(i = 0; i <= 9; i++){
            if(i == 0 && shuru){
                v = F2(pos + 1, mask, taken, false)%MOD;
                u = mul(i, P[sz - pos - 1]);
                u = mul(u, v);
                s = F1(pos + 1, mask, taken, false, true)%MOD;
                s = add(s, u);
                ret = add(ret, s);
            }
            else{
                if(!(mask & (1LL << i))){
                    v = F2(pos + 1, mask | (1LL << i), taken + 1, false)%MOD;
                    u = mul(i, P[sz - pos - 1]);
                    u = mul(u, v);
                    s = F1(pos + 1, mask | (1LL << i), taken + 1, false, false)%MOD;
                    s = add(s, u);
                    ret = add(ret, s);
                }
                else{
                    v = F2(pos + 1, mask, taken, false)%MOD;
                    u = mul(i, P[sz - pos - 1]);
                    u = mul(u, v);
                    s = F1(pos + 1, mask, taken, false, false)%MOD;
                    s = add(s, u);
                    ret = add(ret, s);
                }
            }
        }
    }
    return dp1[pos][mask][taken][sFlag] = ret;
}
void digitize(LL x){
    LL v = x;
    digit.clear();
    while(v != 0){
        digit.pub(v%10);
        v /= 10;
    }
    reverse(digit.begin(), digit.end());
}
void input(){
    LL i, j;
    pre();
    slll(l, r, k);
}
void solve(){
    LL i, j, R, L, ret;
    digitize(r);
    mem(dp1, -1);
    mem(dp2, -1);
    R = F1(0, 0, 0, true, true)%MOD;
//    pl(R);NL;
    digitize(l - 1);
    mem(dp1, -1);
    mem(dp2, -1);
    L = F1(0, 0, 0, true, true)%MOD;
//    pl(L);NL;
    ret = add(R, -L);
    pl(ret);NL;
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
}
