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
#define nl puts("")
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf %lf",&a,&b)
#define sddd(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sp printf(" ")
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define mpr make_pair
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
    cout<<ara[i];nl;\
}
#define pstructvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i];nl;\
}
#define pstructstl(stl,x)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    x=*it;\
    cout<<x;nl;\
}\
nl;
#define pstl(stl)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    if(it!=stl.begin()){sp;}\
    pi(*it);\
}\
nl;
#define ppairvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i].first;sp;cout<<vec[i].second;printf("\n");\
}
#define ppairara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i].first;sp;cout<<ara[i].second;printf("\n");\
}
#define pppairvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;sp;cout<<vec[i][j].second;nl;\
    }\
}
#define pppairara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;nl;\
    }\
}
#define SZ 2 * 100010
using namespace std;
//bool status[100010];
//vector <int> prime;
//void siv(){
//    int N = 100005, i, j; prime.clear();
//    int sq = sqrt(N);
//    for(i = 4; i <= N; i += 2){ status[i] = true; }
//    for(i = 3; i <= sq; i+= 2){
//        if(status[i] == false){
//            for(j = i * i; j <= N; j += i){ status[j] = true; }
//        }
//    }
//    status[1] = true;
//    for1(i, N){ if(!status[i]){ prime.pub(i); } }
//}
inline int add(int _a, int _b){
    if(_a < 0){ _a = _a + MOD; }
    if(_b < 0){ _b = _b + MOD; }
    if(_a + _b > MOD){ return _a + _b - MOD; }
    return _a + _b;
//    return (_a + _b) % MOD;
}
inline int mul(int _a, int _b){
//    _a = (_a + MOD) % MOD;
//    _b = (_b + MOD) % MOD;
    if(_a < 0){ _a = _a + MOD; }
    if(_b < 0){ _b = _b + MOD; }
    return (_a * 1ll * _b) % MOD;
}
struct matrix{
    int a, b, c, d;
    matrix(){}
    matrix(int _a, int _b, int _c, int _d){ a = _a, b = _b, c = _c, d = _d; }
    matrix operator +(const matrix & o) const{
        return matrix(add(a, o.a), add(b, o.b), add(c, o.c), add(d, o.d));
    }
    matrix operator -(const matrix & o) const{
        return matrix(add(a, -o.a), add(b, -o.b), add(c, -o.c), add(d, -o.d));
    }
    matrix operator *(const matrix & o) const{
        return matrix(add(mul(a, o.a), mul(b, o.c)), add(mul(a, o.b), mul(b, o.d)), add(mul(c, o.a), mul(d, o.c)), add(mul(c, o.b), mul(d, o.d)));
    }
    bool operator !=(const matrix & o) const{
        if(a != o.a || b != o.b || c != o.c || d != o.d){ return true; }
        return false;
    }
    void print(){
        pii(a, b); nl;
        pii(c, d); nl;
    }
}fib, fibP[SZ], unit, zero, invFib;
struct seg{
    matrix t, sum, lz;
    seg(){}
    seg(matrix _t, matrix _sum, matrix _lz){ t = _t, sum = _sum, lz = _lz; }
}tree[4 * SZ + 10];
int n, q;
vector <int> adj[SZ];
int hNo[SZ], hHd[SZ], hSz[SZ], hPos[SZ], cLink[SZ], ht[SZ], mxht;
int sbtr[SZ], hCnt = 0, ndCnt = 0, mark[SZ];
vector <int> vrtx;
matrix matExpo(matrix z, ll p){
    ll i, j; matrix ret = unit;
    for(i = p; i != 0; i >>= 1){ if(i % 2 == 1){ ret = ret * z; } z = z * z; }
    return ret;
}
void powering(){
    int i, j;
    unit = matrix(1, 0, 0, 1), zero = matrix(0, 0, 0, 0);
    fib = matrix(1, 1, 1, 0); invFib = matrix(0, 1, 1, MOD - 1);
    for(i = 2, fibP[0] = unit, fibP[1] = fib; i <= mxht; i++){
        fibP[i] = fibP[i - 1] * fib;
    }
}
void dfs(int src, int par){
    int i, j; sbtr[src] = 1;
    for0(i, adj[src].size()){
        int u = adj[src][i];
        if(u != par){ dfs(u, src); sbtr[src] += sbtr[u]; }
    }
}
void bldHld(int src, int par, bool f, int d){
    int i, j, bg = -1, mx = -1, u; vrtx.push_back(src); ht[src] = d, mxht = max(mxht, ht[src]);
    if(f){ hCnt++, hHd[hCnt - 1] = src, hSz[hCnt - 1] = 0, cLink[hCnt - 1] = par; }
    hNo[src] = hCnt - 1, hPos[src] = ndCnt++, hSz[hCnt - 1]++;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par){ if(sbtr[u] > mx){ mx = sbtr[u], bg = u; } }
    }
    if(bg != -1){ bldHld(bg, src, false, d + 1); }
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par && u != bg){ bldHld(u, src, true, d + 1); }
    }
}
void makeHld(){
    int i, j;mxht = -1, dfs(0, -1);
    hCnt = 0, ndCnt = 0, vrtx.clear();
    bldHld(0, -1, true, 0);
    for0(i, hCnt){ mark[i] = -1; }
//    pvec(i, vrtx);
//    for0(i, vrtx.size()){
//        int idx = vrtx[i];
//        piii(idx, hNo[idx], hPos[idx]); sp; pi(cLink[hNo[idx]]); nl;
//    }
}
int getLca(int u, int v){
    int i, j, nd = u;
    vector <int> vec;
    while(1){
        int no = hNo[nd]; mark[no] = nd; vec.push_back(no);
        if(no == 0){ break; } nd = cLink[no];
    }
    nd = v;
    while(1){
        int no = hNo[nd];
        if(mark[no] != -1){
            int ret = mark[no]; for0(i, vec.size()){ mark[vec[i]] = -1; }
            if(ht[nd] < ht[ret]){ return nd; }
            else{ return ret; }
        }
        nd = cLink[no];
    }
    return -1;
}
void input(){
    int i, j;
    sii(n, q);
    for(i = 1; i <= n - 1; i++){
        int u, v; si(u); v = i + 1, u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }
}
void mrg(int iter, bool f){
    if(!f){ tree[iter].t = tree[2 * iter + 1].t + tree[2 * iter + 2].t; }
    else{ tree[iter].sum = tree[2 * iter + 1].sum + tree[2 * iter + 2].sum; }
}
void makeTree(int lo, int hi, int iter){
    int mid = (lo + hi) >> 1;
    if(lo == hi){
        int h = ht[vrtx[lo]];
        tree[iter] = seg(fibP[h], zero, zero);
        return;
    }
    else if(lo < hi){
        makeTree(lo, mid, 2 * iter + 1);
        makeTree(mid + 1, hi, 2 * iter + 2);
        mrg(iter, false);
    }
}
void lazyUp(int iter, matrix & z){
    tree[iter].lz = tree[iter].lz + z;
    tree[iter].sum = tree[iter].sum + tree[iter].t * z;
}
void pushDown(int iter){
    if(tree[iter].lz != zero){
        lazyUp(2 * iter + 1, tree[iter].lz);
        lazyUp(2 * iter + 2, tree[iter].lz);
        tree[iter].lz = zero;
    }
}
void update(int lo, int hi, int iter, int l, int r, matrix & z){
    int mid = (lo + hi) >> 1;
//    pii(lo, hi); nl;
    if(l > r){ return; }
    if(l <= lo && r >= hi){ lazyUp(iter, z); return; }
    else if(l > hi || r < lo){ return; }
    else{
        pushDown(iter);
        update(lo, mid, 2 * iter + 1, l, r, z);
        update(mid + 1, hi, 2 * iter + 2, l, r, z);
        mrg(iter, true);
    }
}
matrix query(int lo, int hi, int iter, int l, int r){
//    pii(lo, hi); nl;
    int mid = (lo + hi) >> 1;
    if(l > r){ return zero; }
    if(l <= lo && r >= hi){ return tree[iter].sum; }
    else if(l > hi || r < lo){ return zero; }
    else{
        pushDown(iter);
        matrix retl = query(lo, mid, 2 * iter + 1, l, r);
        matrix retr = query(mid + 1, hi, 2 * iter + 2, l, r);
        mrg(iter, true);
        return retl + retr;
    }
}
matrix pathQuery(int u, int v){
    int i, j, hd;
    matrix ret = zero;
    while(1){
        if(ht[hHd[hNo[u]]] < ht[hHd[hNo[v]]]){ swap(u, v); }
//        pii(u, v); nl;
        if(hNo[u] == hNo[v]){
            if(hPos[u] < hPos[v]){ swap(u, v); }
            ret = ret + query(0, n - 1, 0, hPos[v], hPos[u]);
            return ret;
        }
        hd = hHd[hNo[u]];
        ret = ret + query(0, n - 1, 0, hPos[hd], hPos[u]);
        u = cLink[hNo[u]];
    }
    return zero;
}
void solve(){
    makeHld();
    powering();
    makeTree(0, n - 1, 0);
    int i, j, u, v;
    matrix ret;
    ll k;
    char tp;
    for0(i, q){
        scanf(" %c", &tp);
        if(tp == 'U'){
            si(u), sl(k), u--;
            if(k - (ll)ht[u] - 1ll < 0){ ret = matExpo(invFib, abs(k - (ll)ht[u] - 1ll)); }
            else {ret = matExpo(fib, k - (ll)ht[u] - 1); }
            update(0, n - 1, 0, hPos[u], hPos[u] + sbtr[u] - 1, ret);
        }
        else{
            sii(u, v), u--, v--;
            ret = pathQuery(u, v);
            pi(ret.a); nl;
        }
    }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    int i, j;
    input();
    solve();
}
