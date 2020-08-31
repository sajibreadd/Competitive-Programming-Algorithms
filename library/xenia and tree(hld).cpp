/*********xenia and tree (heavy light decomposition)***********/
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
vector <int> adj[SZ];
int ht[SZ];
struct TABLE{
    int sparse[SZ][20], n, lg;
    vector <int> sorted;
    TABLE(){}
    void init(int _n){
        n = _n;
        sorted.clear();
    }
    void dfs(int src, int par, int d){
        int i, j, u, w; ht[src] = d;
        for(i = 0; i < adj[src].size(); i++){
            u = adj[src][i];
            if(u != par){
                sparse[u][0] = u;
                sparse[u][1] = src;
                dfs(u, src, d + 1);
            }
        }
    }
    static bool cmp(int lhs, int rhs){
        return ht[lhs] < ht[rhs];
    }
    void makeTable(){
        int i, j, k, l, mxht = -1, u, sz, w, v;
        dfs(0, -1, 0);//0 is root
        sorted.clear();
        for(i = 0; i < n; i++){
            mxht = max(mxht, ht[i]);
            sorted.pub(i);
        }
        sort(sorted.begin(), sorted.end(), cmp);
        i = 1; lg = 0;
        while(i <= mxht){
            i *= 2;
            lg++;
        }
        for(i = 0; i < lg + 1; i++){
            u = sorted[0];
            sparse[u][i] = u;
        }
        sz = sorted.size();
        for(i = 1; i <= sz - 1; i++){
            u = sorted[i];
            for(j = 2; j <= lg; j++){
                w = sparse[u][j - 1];
                v = sparse[w][1];
                sparse[u][j] = sparse[v][j - 1];
            }
        }
    }
    int query(int a, int b){
        int i, j, u, v;
        if(ht[a] > ht[b]){swap(a, b);}
        for(i = lg; i >= 0; i--){
            if(ht[a] == ht[b]){break;}
            u = sparse[b][i];
            if(ht[u] > ht[a]){
                b = sparse[u][1];
            }
        }
        for(i = lg; i >= 0; i--){
            if(a == b){break;}
            u = sparse[a][i];
            v = sparse[b][i];
            if(u != v){
                a = sparse[u][1];
                b = sparse[v][1];
            }
        }
        return a;
    }
};
struct TREE{
    int dpt[2], dif, lz;
    TREE(){}
    TREE(int _d1, int _d2, int _dif, int _lz){
        dpt[0] = _d1;
        dpt[1] = _d2;
        dif = _dif;
        lz = _lz;
    }
}tree[4*SZ + 10];
int n, m;
bool global;
TABLE table;
/**hld starts here***/
int hldNo[SZ], hldHead[SZ], hldSz[SZ], hldPos[SZ], chainLink[SZ];
int sbtr[SZ], hldCnt = 0, nodeCnt = 0;
vector <int> vrtx;
int dfs(int src, int par){
    int i, j, u;
    sbtr[src] = 1;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par){
            sbtr[src] += dfs(u, src);
        }
    }
    return sbtr[src];
}
void bldHld(int src, int par, bool f){
    int i, j, bigChild = -1, mx = -1, u;
    vrtx.pub(src);
    if(f){
        hldCnt++;
        hldHead[hldCnt - 1] = src;
        hldSz[hldCnt - 1] = 0;
        chainLink[hldCnt - 1] = par;
    }
    hldNo[src] = hldCnt - 1;
    hldPos[src] = nodeCnt++;
    hldSz[hldCnt - 1]++;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par){
            if(sbtr[u] > mx){
                mx = sbtr[u];
                bigChild = u;
            }
        }
    }
    if(bigChild != -1){
        bldHld(bigChild, src, false);
    }
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par && u != bigChild){
            bldHld(u, src, true);
        }
    }
}
void makeHld(){
    int i, j, s = dfs(0, -1);//here 0 is root
    hldCnt = 0; nodeCnt = 0; vrtx.clear();
    bldHld(0, -1, true);
}
void mrg(int iter){
    tree[iter].dpt[0] = max(tree[2*iter + 1].dpt[0], tree[2*iter + 2].dpt[0]);
    tree[iter].dpt[1] = min(tree[2*iter + 1].dpt[1], tree[2*iter + 2].dpt[1]);
    tree[iter].dif = min(tree[2*iter + 1].dif, tree[2*iter + 2].dif);
}
void makeTree(int lo, int hi, int iter){
    int i, j, mid = (lo + hi)/2;
    if(lo == hi){
        tree[iter] = TREE(ht[vrtx[lo]], INF, INF - 2*ht[vrtx[lo]], INF);
        return;
    }
    else if(lo < hi){
        tree[iter].lz = INF;
        makeTree(lo, mid, 2*iter + 1);
        makeTree(mid + 1, hi, 2*iter + 2);
        mrg(iter);
    }
}
void lazyUpdate(int iter){
    if(tree[iter].lz < tree[iter].dpt[1]){
        tree[iter].dpt[1] = tree[iter].lz;
        tree[iter].dif = tree[iter].dpt[1] - 2*tree[iter].dpt[0];
    }
}
void pushDown(int iter){
    tree[2*iter + 1].lz = min(tree[2*iter + 1].lz, tree[iter].lz);
    lazyUpdate(2*iter + 1);
    tree[2*iter + 2].lz = min(tree[2*iter + 2].lz, tree[iter].lz);
    lazyUpdate(2*iter + 2);
    tree[iter].lz = INF;
}
void rightUpdate(int lo, int hi, int iter, int v){
    int i, j, mid = (lo + hi)/2;
    if(tree[iter].dpt[1] > v){
        tree[iter].lz = min(tree[iter].lz, v);
        lazyUpdate(iter);
        return;
    }
    else if(lo == hi){return;}
    else if(tree[2*iter + 2].dpt[1] <= v){
        pushDown(iter);
        rightUpdate(mid + 1, hi, 2*iter + 2, v);
    }
    else{
        pushDown(iter);
        rightUpdate(mid +1, hi, 2*iter + 2, v);
        rightUpdate(lo, mid, 2*iter + 1, v);
    }
    mrg(iter);
}
void update(int lo, int hi, int iter, int l, int r, int v){
    int i, j, mid = (lo + hi)/2;
    if(l <= lo && r >= hi){
        if(tree[iter].dpt[1] > v){
            tree[iter].lz = min(tree[iter].lz, v);
            lazyUpdate(iter);
        }
        else if(tree[iter].dpt[1] <= v && !global){
            global = true;
            rightUpdate(lo, hi, iter, v);
        }
        return;
    }
    if(l > hi || r < lo){return;}
    else{
        pushDown(iter);
        update(mid + 1, hi, 2*iter + 2, l, r, v);
        update(lo, mid, 2*iter + 1, l, r, v);
        mrg(iter);
    }
}
int query(int lo, int hi, int iter, int l, int r){
    int i, j, mid = (lo + hi)/2;
    if(l <= lo && r >= hi){
        return tree[iter].dif;
    }
    else if(l > hi || r < lo){
        return INF;
    }
    else{
        pushDown(iter);
        int s1 = query(lo, mid, 2*iter + 1, l, r);
        int s2 = query(mid + 1, hi, 2*iter + 2, l, r);
        mrg(iter);
        return min(s1, s2);
    }
}
int query(int u, int v){// here v is ancestor of u querying from u to ancestor v
    int i, j, s = u, e, ret = INF, ans;
    while(1){
        if(hldHead[hldNo[s]] == hldHead[hldNo[v]]){
            e = v;
            ans = query(0, n - 1, 0, hldPos[e], hldPos[s]);
            ret = min(ret, ans);
            break;
        }
        e = hldHead[hldNo[s]];
        ans = query(0, n - 1, 0, hldPos[e], hldPos[s]);
        ret = min(ret, ans);
        s = chainLink[hldNo[s]];
    }
    return ht[u] + ret;
}
void update(int u, int v){//here v is ancestor of u querying from u to ancestor v
    int i, j, s = u, e;
    global = false;
    while(1){
        if(hldHead[hldNo[s]] == hldHead[hldNo[v]]){
            e = v;
            update(0, n - 1, 0, hldPos[e], hldPos[s], ht[u]);
            break;
        }
        e = hldHead[hldNo[s]];
        update(0, n - 1, 0, hldPos[e], hldPos[s], ht[u]);
        if(global){break;}
        s = chainLink[hldNo[s]];
    }
//    pi(global);NL;
}
void input(){
    int i, j, u, v;
    sii(n, m);
    for0(i, n + 2){
        adj[i].clear();
    }
    table.init(n);
    for0(i, n - 1){
        sii(u, v); u--; v--;
        adj[u].pub(v);
        adj[v].pub(u);
    }
    makeHld();
    table.makeTable();
}
void solve(){
    int i, j, t, u, ret, s;
    makeTree(0, n - 1, 0);
    update(0, 0);
    for0(i, m){
        sii(t, s); s--;
        if(t == 1){
            update(s, 0);
//            pi(tree[0].dif);NL;
        }
        else{
            ret = query(s, 0);
            pi(ret);NL;
        }
    }
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
}

