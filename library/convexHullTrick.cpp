/********convex hull trick*****/
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
#define eps 1e-8
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n | (1<<pos))
#define para(a,b,ara)\
for(int i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    pi(ara[i]);\
}\
printf("\n");
#define pvec(vec)\
for(int i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    pi(vec[i]);\
}\
printf("\n");
#define ppara(n,m,ara)\
for(int i=0;i<n;i++){\
    for(int j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        pi(ara[i][j]);\
    }\
    printf("\n");\
}
#define ppvec(n,vec)\
for(int i=0;i<n;i++){\
    for(int j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        pi(vec[i][j]);\
    }\
    printf("\n");\
}
#define sara(a,b,ara)\
for(int i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}
#define pstructara(a,b,ara)\
for(int i=a;i<=b;i++){\
    cout<<ara[i];NL;\
}
#define pstructvec(vec)\
for(int i=0;i<vec.size();i++){\
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
//	int N=1005,i,j;prime.clear();
//	int sq=sqrt(N);
//	for(i=4;i<=N;i+=2){status[i]=1};
//	for(i=3;i<=sq;i+=2){
//		if(status[i]==0){
//			for(j=i*i;j<=N;j+=i){status[j]=1;}
//		}
//	}
//	status[1]=1;
//    for1(i,N){
//        if(!status[i]){prime.pub(i);}
//    }
//}
struct line{
    LL m,c;
    line(){}
    line(LL _m,LL _c){
        m=_m;c=_c;
    }
    std::ostream & dump(std::ostream &os)const{
        return os<<"m="<<m
                 <<"c="<<c;
    }
};
std::ostream & operator<<(ostream &os,line &s){
    return s.dump(os);
}
///for minimization slope should be sorted in decreasing order
///for maximization slope should be sorted in ascending order
struct CHT{
    vector <line> vec;
    CHT(){vec.clear();}
    bool checkLine(line l1,line l2,line l3){
        return ((double)(l2.c-l1.c))/((double)(l1.m-l2.m))>=((double)(l3.c-l1.c))/((double)(l1.m-l3.m));
    }
    void insert(line l){
        int sz;
        bool f;
        if(vec.size()==0){
            vec.pub(l);
        }
        else if(vec.size()==1){
            vec.pub(l);
        }
        else{
            while(1){
                sz=vec.size();
                f=checkLine(vec[sz-1],vec[sz-2],l);
                if(!f){break;}
                vec.pop_back();
            }
            vec.pub(l);
        }
    }
    bool checkMid(LL mid,LL x){
        LL m1,m2,c1,c2;
        m1=vec[mid].m;
        c1=vec[mid].c;
        m2=vec[mid-1].m;
        c2=vec[mid-1].c;
        return (double)(c2-c1)/(double)(m1-m2)<=(double)x;
    }
    LL query(LL x){
        if(vec.size()==1){
            return (vec[0].m*x)+vec[0].c;
        }
        LL lo=0,sz=vec.size(),hi=sz-1,mid;
        while(lo<hi){
            mid=(lo+hi+1)/2;
            if(checkMid(mid,x)){
                lo=mid;
            }
            else{
                hi=mid-1;
            }
        }
        return (vec[lo].m*x)+vec[lo].c;
    }
};
LL n,ara[100010],bra[100010];
LL dp[100010];
CHT cht;
void input(){
    LL i,j;
    scanf("%I64d",&n);
    for0(i,n){scanf("%I64d",&ara[i]);}
    for0(i,n){scanf("%I64d",&bra[i]);}
}
void solve(){
    LL i,j,s;
    cht=CHT();
    for0(i,n){
        if(i==0){
            dp[i]=0;
            cht.insert(line(bra[i],dp[i]));
        }
        else{
            dp[i]=cht.query(ara[i]);
            cht.insert(line(bra[i],dp[i]));
        }
    }
    printf("%I64d\n",dp[n-1]);
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
    return 0;
}
