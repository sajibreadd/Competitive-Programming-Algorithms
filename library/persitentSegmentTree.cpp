/******** persitent segment tree for distinct number in range*******************/
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
#define SZ 100005
#define RNG 100005
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
struct TREE{
    int frq;
    int link[2];
    TREE(){}
    TREE(int _frq){
        frq = _frq;
        link[0] = link[1] = -1;
    }
};
vector <TREE> tree;
int n, ara[SZ], nodeCnt = 1, points[SZ], mp[SZ], q;
void mrg(int iter){
    int a = tree[tree[iter].link[0]].frq;
    int b = tree[tree[iter].link[1]].frq;
    tree[iter].frq = a + b;
}
void makeTree(int lo, int hi, int iter){
    int i, j, mid = (lo + hi)/2;
    tree.pub(TREE(0));
    if(lo == hi){return;}
    else if(lo < hi){
        tree[iter].link[0] = nodeCnt++;
        makeTree(lo, mid, tree[iter].link[0]);

        tree[iter].link[1] = nodeCnt++;
        makeTree(mid + 1, hi, tree[iter].link[1]);
        mrg(iter);
    }
}
void update(int lo, int hi, int nw, int pv, int idx, int v){
    int i, j, mid = (lo + hi)/2;
    if(lo == hi){
        tree.pub(TREE(v));
        return;
    }
    else if(idx >= lo && idx <= mid){
        tree.pub(TREE(0));
        tree[nw].link[0] = nodeCnt++;
        tree[nw].link[1] = tree[pv].link[1];
        update(lo, mid, tree[nw].link[0], tree[pv].link[0], idx, v);
    }
    else{
        tree.pub(TREE(0));
        tree[nw].link[0] = tree[pv].link[0];
        tree[nw].link[1] = nodeCnt++;
        update(mid + 1, hi, tree[nw].link[1], tree[pv].link[1], idx, v);
    }
    mrg(nw);
}
TREE query(int lo, int hi, int iter, int l, int r){
    int i, j, mid = (lo + hi)/2, a, b;
    if(l <= lo && r >= hi){
        return tree[iter];
    }
    else if(l > hi || r < lo){
        return TREE(0);
    }
    else{
        TREE s1 = query(lo, mid, tree[iter].link[0], l, r);
        TREE s2 = query(mid + 1, hi, tree[iter].link[1], l, r);
        a = s1.frq;
        b = s2.frq;
        return TREE(a + b);
    }
}
void input(){
    int i, j;
    tree.clear();
    sii(n, q);
    for0(i, n){
        scanf("%d", &ara[i]);
        mp[ara[i]] = -1;
    }
    nodeCnt = 0;
}
void solve(){
    int i, j, nw, pv, l, r, idx, ret;
    TREE s;
    points[n] = 0;nodeCnt++;
    makeTree(0, n - 1, points[n]);
    pv = points[n];
    for(i = n - 1; i >= 0; i--){
        nw = nodeCnt++;
        update(0, n - 1, nw, pv, i, 1);
        pv = nw;
        if(mp[ara[i]] != -1){
            nw = nodeCnt++;
            update(0, n - 1, nw, pv, mp[ara[i]], 0);
            pv = nw;
        }
        mp[ara[i]] = i;
        points[i] = pv;
    }
    for0(i, q){
        sii(l, r); l--, r--;
        idx = points[l];
        s = query(0, n - 1, idx, l, r);
        ret = s.frq;
        pi(ret);NL;
    }
}
int main(){
    int i, j, ts,cs;
    si(ts);
    for0(cs, ts){
        input();
        printf("Case %d:\n", cs + 1);
        solve();
    }
}
