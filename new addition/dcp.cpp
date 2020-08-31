#include <ext/pb_ds/assoc_container.hpp>
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
#define SZ 4 * 100010
using namespace std;
using namespace __gnu_pbds;
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
struct DSU{
   int parent[SZ];
   vector < pair <int, int > > roll;
   void ini(int n){
      int i, j;
      for1(i, n){ parent[i] = i; }
   }
   int get_parent(int u, bool f){
      if(parent[u] == u){ return u; }
      if(!f){ return parent[u] = get_parent(parent[u], f); }
      else{
         int x = get_parent(parent[u], f);
         roll.push_back(mpr(u, parent[u]));
         return parent[u] = x;
      }
   }
   void union_tree(int u, int v, bool f){
      int pu = get_parent(u, f), pv = get_parent(v, f);
      if(pu == pv){ return; }
      int x = rand() % 2;
      if(!f){
         if(x == 0){ parent[pv] = pu; }
         else{ parent[pu] = pv; }
      }
      else{
         if(x == 0){
            roll.push_back(mpr(pv, parent[pv]));
            parent[pv] = pu;
         }
         else{
            roll.push_back(mpr(pu, parent[pu]));
            parent[pu] = pv;
         }
      }
   }
   bool check_connenction(int u, int v){
      int pu = get_parent(u, true), pv = get_parent(v, true);
      return (pu == pv);
   }
   void roll_back(){
      pair <int, int> x;
      while(!roll.empty()){
         x = roll.back();
         parent[x.first] = x.second;
         roll.pop_back();
      }
   }
}dsu;
struct chash {
    ll operator()(pair <int, int> x) const { return x.first << 31ll + (ll)x.second; }
};
const int magic = 350;
int n, m, u_cnt = 0, sol[SZ], bucket[SZ], q_type[SZ];
pair <int, int> query[SZ], edge_list[SZ];
gp_hash_table < pair <int, int >, int, chash> mp;
gp_hash_table < pair <int, int>, bool, chash> yes;
bool state[SZ], out[SZ];
void input(){
   int i, j, l, r; sii(n, m);
   u_cnt = 0;
   for0(i, m){
      siii(q_type[i], query[i].first, query[i].second);
      l = query[i].first, r = query[i].second;
      l = ((l - 1) % n) + 1, r = ((r - 1) % n) + 1;
      if(l > r){ swap(l, r); }
      if(!yes[mpr(l, r)]){
         yes[mpr(l, r)] = true; mp[mpr(l, r)] = u_cnt++;
         edge_list[u_cnt - 1] = mpr(l, r);
      }
      l = query[i].first, r = query[i].second;
      l = (l % n) + 1, r = (r % n) + 1;
      if(l > r){ swap(l, r); }
      if(!yes[mpr(l, r)]){
         yes[mpr(l, r)] = true; mp[mpr(l, r)] = u_cnt++;
         edge_list[u_cnt - 1] = mpr(l, r);
      }
   }
}
void rebuild(int pos){
   int i, j, l, r, idx, pv;
   mem(state, false), mem(out, false); dsu.ini(n);
   for(i = 0; i <= pos; i++){
      if(q_type[i] == 2){ continue; }
      pv = i == 0 ? 0 : sol[i - 1];
      l = query[i].first, r = query[i].second;
      l = ((l + pv - 1) % n) + 1, r = ((r + pv - 1)  % n) + 1;
      if(l > r){ swap(l, r); }
      idx = mp[mpr(l, r)];
      state[idx] ^= true;
      bucket[i] = idx;
   }
   for(i = (pos / magic + 1) * magic; i < m && i < (pos / magic + 2) * magic; i++){
      if(q_type[i] == 2){ continue; }
      l = query[i].first, r = query[i].second;
      l = ((l - 1) % n) + 1, r = ((r - 1) % n) + 1;
      idx = mp[mpr(l, r)]; out[idx] = true;
      if(l > r){ swap(l, r); }
      l = query[i].first, r = query[i].second;
      l = (l % n) + 1, r = (r % n) + 1;
      if(l > r){ swap(l, r); }
      idx = mp[mpr(l, r)]; out[idx] = true;
   }
   for(i = 0; i <= pos; i++){
      if(q_type[i] == 2){ continue; }
      idx = bucket[i];
      if(state[idx] && out[idx]){ continue; }
      else if(state[idx]){ dsu.union_tree(edge_list[idx].first, edge_list[idx].second, false); }
   }
}
void solve(){
   int i, j, last = 0, idx, l, r, pv, a, b;
//   ppairara(i, 0, m - 1, query);
   for(i = 0, dsu.ini(n); i < m; i++){
      sol[i] = i == 0 ? 0 : sol[i - 1];
      if(q_type[i] == 2){
         for(j = (i / magic) * magic; j < i; j++){
            if(q_type[j] == 2){ continue; }
            pv = j == 0 ? 0 : sol[j - 1];
            l = query[j].first, r = query[j].second;
            l = ((l + pv - 1) % n) + 1, r = ((r + pv - 1) % n) + 1;
            if(l > r){ swap(l, r); }
            idx = mp[mpr(l, r)];
            bucket[j] = idx;
            state[idx] ^= 1;
         }
         for(j = (i / magic) * magic; j < i; j++){
            if(q_type[j] == 2){ continue; }
            idx = bucket[j];
            if(state[idx]){
               dsu.union_tree(edge_list[idx].first, edge_list[idx].second, true);
            }
         }
         for(j = (i / magic) * magic; j < i; j++){
            if(q_type[j] == 2){ continue; }
            idx = bucket[j];
            state[idx] ^= 1;
         }
         pv = i == 0 ? 0 : sol[i - 1];
         l = query[i].first, r = query[i].second;
         l = ((l + pv - 1) % n) + 1, r = ((r + pv - 1) % n) + 1;
         if(l > r){ swap(l, r); }
         sol[i] = dsu.check_connenction(l, r);
         dsu.roll_back();
      }
      if((i + 1) % magic == 0){ rebuild(i); }
   }
   for0(i, m){
      if(q_type[i] == 2){ pi(sol[i]); }
   }
   nl;
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    input();
    solve();
}
