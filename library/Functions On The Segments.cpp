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
#define MOD 1000000000
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
#define SZ 75010
#define RNG 200010
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
struct DATA{
    LL l, r, yy1, a, b, yy2;
    DATA(){}
    DATA(LL _l, LL _r, LL _yy1, LL _a, LL _b, LL _yy2){
        l = _l; r= _r; yy1 = _yy1;
        a = _a; b = _b; yy2 = _yy2;
    }
}ara[SZ];
struct TREE{
    LL yy1, a, b, yy2, link[2];
    TREE(){}
    TREE(LL _yy1, LL _a, LL _b, LL _yy2){
        yy1 = _yy1; a = _a; b = _b; yy2 = _yy2;
    }
};
LL n, m, nodeCnt[2], points[2][SZ];
vector <TREE> tree[2];
void mrg(LL iter, bool tp){
    tree[tp][iter].yy1 = tree[tp][tree[tp][iter].link[0]].yy1 + tree[tp][tree[tp][iter].link[1]].yy1;
    tree[tp][iter].a = tree[tp][tree[tp][iter].link[0]].a + tree[tp][tree[tp][iter].link[1]].a;
    tree[tp][iter].b = tree[tp][tree[tp][iter].link[0]].b + tree[tp][tree[tp][iter].link[1]].b;
    tree[tp][iter].yy2 = tree[tp][tree[tp][iter].link[0]].yy2 + tree[tp][tree[tp][iter].link[1]].yy2;
}
void makeTree(LL lo, LL hi, LL iter, bool tp){
    LL i, j, mid = (lo + hi)/2;
    tree[tp].pub(TREE(0, 0, 0, 0));
    if(lo == hi){}
    else if(lo < hi){
        tree[tp][iter].link[0] = nodeCnt[tp]++;
        makeTree(lo, mid, tree[tp][iter].link[0], tp);
        tree[tp][iter].link[1] = nodeCnt[tp]++;
        makeTree(mid + 1, hi, tree[tp][iter].link[1], tp);
        mrg(iter, tp);
    }
}
void update(LL lo, LL hi, LL nw, LL pv, bool tp, LL idx, LL idy){
    LL i, j, mid = (lo + hi)/2;
    if(lo == hi){
        LL yy1, a, b, yy2;
        yy1 = tree[tp][pv].yy1 + ara[idy].yy1;
        a = tree[tp][pv].a + ara[idy].a;
        b = tree[tp][pv].b + ara[idy].b;
        yy2 = tree[tp][pv].yy2 + ara[idy].yy2;
        tree[tp].pub(TREE(yy1, a, b, yy2));
        return;
    }
    else if(idx >= lo && idx <= mid){
        tree[tp].pub(TREE(0, 0, 0, 0));
        tree[tp][nw].link[0] = nodeCnt[tp]++;
        tree[tp][nw].link[1] = tree[tp][pv].link[1];
        update(lo, mid, tree[tp][nw].link[0], tree[tp][pv].link[0], tp, idx, idy);
    }
    else{
        tree[tp].pub(TREE(0, 0, 0, 0));
        tree[tp][nw].link[0] = tree[tp][pv].link[0];
        tree[tp][nw].link[1] = nodeCnt[tp]++;
        update(mid + 1, hi, tree[tp][nw].link[1], tree[tp][pv].link[1], tp, idx, idy);
    }
    mrg(nw, tp);
}
TREE query(LL lo, LL hi, LL iter, bool tp, LL l, LL r){
    LL i, j, mid = (lo + hi)/2, yy1, a, b, yy2;
    if(l > r){
        return TREE(0, 0, 0, 0);
    }
    if(l <= lo && r >= hi){
        return tree[tp][iter];
    }
    else if(l > hi || r < lo){
        return TREE(0, 0, 0, 0);
    }
    else{
        TREE s1 = query(lo, mid, tree[tp][iter].link[0], tp, l, r);
        TREE s2 = query(mid + 1, hi, tree[tp][iter].link[1], tp, l, r);
        yy1 = s1.yy1 + s2.yy1;
        a = s1.a + s2.a;
        b = s1.b + s2.b;
        yy2 = s1.yy2 + s2.yy2;
//        pl(yy1);NL;
        return TREE(yy1, a, b, yy2);
    }
}
void input(){
    LL i, j;
    sl(n);
    tree[0].clear(); tree[1].clear();
    for0(i, n){
        slll(ara[i].l, ara[i].r, ara[i].yy1);
        slll(ara[i].a, ara[i].b, ara[i].yy2);
    }
    nodeCnt[0] = nodeCnt[1] = 0;
}
void solve(){
    LL i, j, nw[2], pv[2], l, r, x, sol[2], ret = 0;
    TREE sl[2], sr[2];
    points[0][n] = nodeCnt[0]++;
    points[1][n] = nodeCnt[1]++;
    makeTree(0, RNG, points[0][n], false);
    makeTree(0, RNG, points[1][n], true);
    pv[0] = points[0][n]; pv[1] = points[1][n];
    for(i = n - 1; i >= 0; i--){
        points[0][i] = nodeCnt[0]++;
        nw[0] = points[0][i];
        update(0, RNG, nw[0], pv[0], false, ara[i].l, i);
        pv[0] = nw[0];

        points[1][i] = nodeCnt[1]++;
        nw[1] = points[1][i];
        update(0, RNG, nw[1], pv[1], true, ara[i].r, i);
        pv[1] = nw[1];
    }
//    pl(query(0, RNG, points[0][0], false, 3, RNG).yy1);NL;
//    pl(tree[0][points[0][0]].b);NL;
    sl(m);
    for0(i, m){
        slll(l, r, x); l--; r--;
        x = ((x%MOD) + (ret%MOD))%MOD;
        sl[0] = query(0, RNG, points[0][l], false, x, RNG);
        sr[0] = query(0, RNG, points[0][r + 1], false, x, RNG);
        sol[0] = sl[0].yy1 - sr[0].yy1;

        sl[1] = query(0, RNG, points[1][l], true, 0, x - 1);
        sr[1] = query(0, RNG, points[1][r + 1], true, 0, x - 1);
        sol[1] = sl[1].yy2 - sr[1].yy2;

        ret = tree[0][points[0][l]].a - tree[0][points[0][r + 1]].a;
        ret -= (sl[0].a - sr[0].a);
        ret -= (sl[1].a - sr[1].a);
        ret *= x;
        ret += (tree[0][points[0][l]].b - tree[0][points[0][r + 1]].b);
        ret -= (sl[0].b - sr[0].b);
        ret -= (sl[1].b - sr[1].b);
        ret += (sol[0] + sol[1]);
        pl(ret);NL;
    }
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
}
