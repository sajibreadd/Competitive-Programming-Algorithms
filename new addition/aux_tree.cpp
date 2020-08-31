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
#define SZ 50010
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
int add(int _a, int _b){
    _a = (_a + MOD) % MOD;
    _b = (_b + MOD) % MOD;
    return (_a + _b) % MOD;
}
int mul(int _a, int _b){
    _a = (_a + MOD) % MOD;
    _b = (_b + MOD) % MOD;
    return ((ll)((ll)_a * (ll)_b)) % MOD;
}
struct persistent_seg_tree{
   int link[2], sum;
   void ini(){ mem(link, -1), sum = 0; }
}tree[70 * SZ];
int n, q, sbtr[SZ], centroid, parent[SZ], par_cen[SZ], path_dis[30][SZ], cen_dpt[SZ], t = 0, node_cnt = 0;
vector <int> adj[SZ], adj_cen[SZ], dis[SZ], dis_child[SZ];
bool mark_cen[SZ];
int order[SZ], vrtx[SZ], ith_seg[SZ], ht[SZ];
void dfs0(int src, int par, int d){
   int i, j, u; sbtr[src] = 1, parent[src] = par;
   order[src] = t, vrtx[t++] = src, ht[src] = d;
   for0(i, adj[src].size()){
      u = adj[src][i];
      if(u != par){ dfs0(u, src, d + 1), sbtr[src] += sbtr[u]; }
   }
}
int get_centroid(int src, int par){
   int i, j, u, mx = -1, bg;
   bool is_cen = true;
   for0(i, adj[src].size()){
      u = adj[src][i];
      if(u != par){
         if(sbtr[u] > n / 2){ is_cen = false; }
         if(sbtr[u] > mx){ mx = sbtr[u], bg = u; }
      }
   }
   if(is_cen && n - sbtr[src] <= n / 2){ return src; }
   return get_centroid(bg, src);
}
void get_centroid(int cnn, int root, int src, int par){
   int i, j, u, mx = -1, bg;
   bool is_cen = true;
   if(src == centroid){
      for0(i, adj[src].size()){
         u = adj[src][i];
         if(!mark_cen[u] && u != par){ get_centroid(src, u, u, src); }
      }
      return;
   }
   for0(i, adj[src].size()){
      u = adj[src][i];
      if(u != par && !mark_cen[u]){
         if(sbtr[u] > sbtr[root] / 2){ is_cen = false; }
         if(sbtr[u] > mx){ mx = sbtr[u], bg = u; }
      }
   }
   if(mx == -1 || (is_cen && sbtr[root] - sbtr[src] <= sbtr[root] / 2)){
      adj_cen[cnn].push_back(src), adj_cen[src].push_back(cnn);
      mark_cen[src] = true;
      int p = parent[src];
      while(!mark_cen[p]){ sbtr[p] -= sbtr[src], p = parent[p]; }
      for0(i, adj[src].size()){
         u = adj[src][i];
         if(u != par && !mark_cen[u]){ get_centroid(src, u, u, src); }
      }
      if(mx != -1 && !mark_cen[root]){ get_centroid(src, root, root, parent[root]); }
   }
   else{ get_centroid(cnn, root, bg, src); }
}
void decompose(){
   int i, j;
   t = 0, dfs0(0, -1), centroid = get_centroid(0, -1), t = 0, dfs0(centroid, -1);
   mark_cen[centroid] = true;
   get_centroid(centroid, centroid, centroid, -1);
   t = 0; dfs0(centroid, -1);
   for0(i, n + 2){ mark_cen[i] = false; }
}
void dfs2(int cen, int src, int root, int par, int d, bool tick){
   int i, j, sz = adj_cen[src].size(), cnt = 0, u;
   path_dis[cen_dpt[cen]][src] = d;
   dis[cen].push_back(d); if(tick){ dis_child[root].push_back(d); }
   cnt = root == centroid ? 0 : 1;
   for0(i, adj[src].size()){
      u = adj[src][i];
      if(!tick){
         if(u != par && !mark_cen[u]){
            dfs2(cen, u, adj_cen[src][cnt], src, d + 1, true); cnt++;
         }
         else if(u == par && !mark_cen[u]){
            dfs2(cen, u, adj_cen[src][sz - 1], src, d + 1, true);
         }
      }
      else if(u != par && !mark_cen[u]){
         dfs2(cen, u, root, src, d + 1, true);
      }
   }
}
void dfs1(int src, int par, int level){
   int i, j, u; mark_cen[src] = true, par_cen[src] = par, cen_dpt[src] = level;
   dfs2(src, src, src, parent[src], 0, false);
   sort(dis[src].begin(), dis[src].end());
   for0(i, adj_cen[src].size()){
      u = adj_cen[src][i];
      if(u != par && !mark_cen[u]){
         sort(dis_child[u].begin(), dis_child[u].end());
         dfs1(u, src);
      }
   }
}
int node_in_distance(int u, int d){
   int p = u, i, j, prv, ret = 0, x;
   for(p = u, prv = u; p != -1; ){
      if(p == u){ ret += upper_bound(dis[p].begin(), dis[p].end(), d) - dis[p].begin(); }
      else{
         if(d >= path_dis[cen_dpt[p]][u]){
            x = d - path_dis[cen_dpt[p]][u];
            ret += upper_bound(dis[p].begin(), dis[p].end(), x) - dis[p].begin();
            ret -= upper_bound(dis_child[prv].begin(), dis_child[prv].end(), x) - dis_child[prv].begin();
         }
      }
      prv = p, p = par_cen[p];
   }
}
void mrg(int iter){
   int l = tree[iter].link[0], r = tree[iter].link[1];
   tree[iter].sum = 0;
   if(l != -1){ tree[iter].sum += tree[l].sum; }
   if(r != -1){ tree[iter].sum += tree[r].sum; }
}
void update(int lo, int hi, int pv, int nw, int idx, int v){
   int mid = (lo + hi) >> 1;
   if(lo == hi){
      if(pv == -1){ tree[nw] = v; return; }
      tree[nw] = tree[pv] + v; return;
   }
   if(idx >= lo && idx <= mid){
      if(pv == -1){
         tree[nw].link[0] = node_cnt++, tree[node_cnt - 1].ini();
         tree[nw].link[1] = -1;
         update(lo, mid, -1, tree[nw].link[0], idx, v);
      }
      else{
         tree[nw].link[0] = node_cnt++, tree[node_cnt - 1].ini();
         tree[nw].link[1] = tree[pv].link[1];
         update(lo, mid, tree[pv].link[0], tree[nw].link[0], idx, v);
      }
   }
   else{
      if(pv == -1){
         tree[nw].link[1] = node_cnt++, tree[node_cnt - 1].ini();
         tree[nw].link[0] = -1;
         update(mid + 1, hi, -1, tree[nw].link[1], idx, v);
      }
      else{
         tree[nw].link[1] = node_cnt++, tree[node_cnt - 1].ini();
         tree[nw].link[0] = tree[pv].link[0];
         update(mid + 1, hi, tree[pv].link[1], tree[nw].link[1], idx, v);
      }
   }
   mrg(nw);
}
int query(int lo, int hi, int iter, int l, int r){
   int mid = (lo + hi) >> 1;
   if(l > r){ return 0; }
   if(iter == -1){ return 0; }
   if(l <= lo && r >= hi){ return tree[iter].sum; }
   else if(l > hi || r < lo){ return 0; }
   else{
      int ret = 0, L = tree[iter].link[0], R = tree[iter].link[1];
      if(L != -1){ ret += query(lo, mid, L, l, r); }
      if(R != -1){ ret += query(mid + 1, hi, R, l, r); }
      return ret;
   }
}
int node_in_depth(int u, int d){
   return query(0, n - 1, ith_seg[order[u]], 0, d + ht[u]) -
          query(0, n - 1, ith_seg[order[u] + sbtr[u] - 1], 0, d + ht[u]);
}
void input(){
   int i, j;
   si(n);
   for0(i, n - 1){
      int u, v; sii(u, v);
      adj[u].push_back(v), adj[v].push_back(u);
   }
   decompose();
}
void solve(){
   int i, j, pv, nw;
   node_cnt = 1, tree[node_cnt - 1].ini();
   for(i = n - 1, pv = 0, nw = 0; i >= 0; i--){
      nw = node_cnt++, tree[node_cnt - 1].ini();
      update(0, n - 1, pv, nw, ht[vrtx[i]], 1), pv = nw;
      ith_seg[i] = pv;
   }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    input();
    solve();
}
