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
#define MOD INT_MAX
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
#define SZ 1010
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
LL base = 1995433697LL, prm = 1000000009LL, B[SZ], P[SZ], patternHash, rowHash[SZ][SZ], columnHash[SZ][SZ], hsh[SZ][SZ], n, m, r, c;
char pattern[SZ][SZ], str[SZ][SZ];
LL add(LL _a, LL _b){//here MOD = INT_MAX
    _a = (_a + MOD)%MOD;
    _b = (_b + MOD)%MOD;
    return (_a + _b)%MOD;
}
LL mul(LL _a, LL _b){
    _a = (_a + MOD)%MOD;
    _b = (_b + MOD)%MOD;
    return (_a * _b)%MOD;
}
void Pregenerate(){
    LL i, j, ret = 0, k;
    B[0] = P[0] = 1;
    for1(i, SZ - 2){
        B[i] = mul(B[i - 1], base);
        P[i] = mul(P[i - 1], prm);
    }
    patternHash = 0;
    for(i = n - 1; i >= 0; i--){
        ret = 0;
        for(j = m - 1; j >= 0; j--){
            ret = add(mul(ret, prm), pattern[i][j]);
        }
        patternHash = add(mul(patternHash, base), ret);
    }
    for(i = n; i >= 0; i--){
        if(i == n){
            for(j = m - 1; j >= 0; j--){
                columnHash[i][j] = 0;
            }
            continue;
        }
        rowHash[i][m] = 0;
        for(j = m - 1; j >= 0; j--){
            if(j >= m - c){
                rowHash[i][j] = add(mul(rowHash[i][j + 1], prm), str[i][j]);
            }
            else{
                rowHash[i][j] = add(mul(rowHash[i][j + 1], prm), str[i][j]);
                rowHash[i][j] = add(rowHash[i][j], -mul(P[c], str[i][j + c]));
            }
        }
        for(j = m - 1; j >= 0; j--){
            if(i >= n - r){
                columnHash[i][j] = add(mul(columnHash[i + 1][j], base), str[i][j]);
            }
            else{
                columnHash[i][j] = add(mul(columnHash[i + 1][j], base), str[i][j]);
                columnHash[i][j] = add(columnHash[i][j], -mul(B[r], str[i + r][j]));
            }
        }
    }
    for(i = n - r; i >= 0; i--){
        for(j = m - c; j >= 0; j--){
            if(i == n - r && j == m - c){
                ret = 0;
                for(k = n - 1; k >= i; k--){
                    ret = add(mul(ret, base), rowHash[k][j]);
                }
                hsh[i][j] = ret;
            }
            else if(i == n - r){
                hsh[i][j] = add(mul(hsh[i][j + 1], prm), columnHash[i][j]);
                hsh[i][j] = add(hsh[i][j], -mul(P[c], columnHash[i][j + c]));
            }
            else{
                hsh[i][j] = add(mul(hsh[i + 1][j], base), rowHash[i][j]);
                hsh[i][j] = add(hsh[i][j], -mul(B[r], rowHash[i + r][j]));
            }
        }
    }
}
LL matching(){//returns number of matchings
    LL i, j, cnt = 0;
    for(i = 0; i <= n - r; i++){
        for(j = 0; j <= m - c; j++){
            if(hsh[i][j] == patternHash){
                cnt++;
            }
        }
    }
    return cnt;
}
void input(){
    LL i, j;
    for0(i, r){
        ss(pattern[i]);
    }
    for0(i, n){
        ss(str[i]);
    }
    ppara(i, j, n, m, str);
}
void solve(){
}
int main(){
    //freopen("input.txt","r",stdin);
    LL ret;
    while(scanf("%lld %lld %lld %lld",&r, &c, &n, &m) == 4){//r is row of pattern and c is column patter n is row of grid and m is column of gird
        input();
        Pregenerate();
        ret = matching();
        pl(ret);NL;
    }
}
