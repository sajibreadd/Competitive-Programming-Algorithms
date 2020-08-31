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
#define SZ 3 * 100010
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
int n, m, nd_cnt = 0, k, frbd_cnt = 0;
vector <int> rev[SZ], adj[3 * SZ];
pair <int, int> tree[2 * SZ];
bool bad[SZ], vis[2 * SZ], color[3 * SZ], global;
int compo_cnt = 0;
queue <int> q;
void input(){
   int i, j, u, v;
   siii(n, m, k);
   frbd_cnt = 0;
   for0(i, m){
      sii(u, v); u--, v--;
      if(u == 0 || v == 0){ if(u){ bad[u] = true; } else{ bad[v] = true; } frbd_cnt++; continue; }
      rev[u].push_back(v), rev[v].push_back(u);
   }
}
void make_tree(int lo, int hi, int iter){
   int mid = (lo + hi) >> 1;
   if(lo == hi){ return; }
   else{
      nd_cnt++, tree[iter].first = nd_cnt - 1;
      make_tree(lo, mid, tree[iter].first);
      nd_cnt++, tree[iter].second = nd_cnt - 1;
      make_tree(mid + 1, hi, tree[iter].second);
   }
}
inline void add_edge(int u, int v){
   adj[u].push_back(v);
   adj[v].push_back(u);
}
void add_link(int lo, int hi, int iter, int l, int r, int v){
   if(l > r){ return; }
   int mid = (lo + hi) >> 1, i, j;
   if(l <= lo && r >= hi){
      if(!vis[iter]){
         for(vis[iter] = true, i = lo; i <= hi; i++){
            add_edge(i, iter + n);
         }
      }
      if(!(v >= lo && v <= hi)){ add_edge(v, iter + n); }
      return;
   }
   else if(l > hi || r < lo){ return; }
   else{
      add_link(lo, mid, tree[iter].first, l, r, v);
      add_link(mid + 1, hi, tree[iter].second, l, r, v);
   }
}
//void dfs(int src){
//   int i, j, u;  color[src] = true;
//   if(!bad[src]){ global = true; }
//   for0(i, adj[src].size()){
//      u = adj[src][i];
//      if(!color[u]){ dfs(u); }
//   }
//}
void bfs(int src){
   int i, j, u, v;
   q.push(src);
   while(!q.empty()){
      u = q.front(), q.pop();
      if(!bad[u]){ global = true; }
      for0(i, adj[u].size()){
         v = adj[u][i];
         if(!color[v]){ color[v] = true; q.push(v); }
      }
   }
}
void solve(){
   if(n - 1 - frbd_cnt < k){ ps("impossible\n"); return; }
   int i, j, pv;
   nd_cnt = 1, make_tree(0, n - 1, 0);
   for1(i, n - 1){ rev[i].push_back(0), sort(rev[i].begin(), rev[i].end()); }
   for1(i, n - 1){
      for(pv = -1, j = 0; j < rev[i].size(); j++){
         add_link(0, n - 1, 0, pv + 1, rev[i][j] - 1, i), pv = rev[i][j];
      }
      add_link(0, n - 1, 0, pv + 1, n - 1, i);
   }
   int x = 0;
//   for1(i, n - 1){
//      x += adj[i].size();
//   }
//   pi(x); nl;
   compo_cnt = 0;
   for1(i, n - 1){
      if(!color[i]){
         global = false;
         bfs(i);
         if(!global){ ps("impossible\n"); return; }
         compo_cnt++;
      }
   }
   if(compo_cnt > k){ ps("impossible\n"); return; }
   ps("possible\n");
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
   input();
   solve();
}
