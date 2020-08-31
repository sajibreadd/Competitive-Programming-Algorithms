/*****centroid decomposition*******/
using namespace std;
using namespace __gnu_pbds;
inline int add(int _a, int _b, int md){
//  _a = (_a + md) % md;
//  _b = (_b + md) % md;
   if(_a < 0){ _a += md; }
   if(_b < 0){ _b += md; }
   if(_a + _b >= md){ return _a + _b - md; }
   return _a + _b;
}
inline int mul(int _a, int _b, int md){
   if(_a < 0){ _a += md; }
   if(_b < 0){ _b += md; }
   return ((ll)((ll)_a * (ll)_b)) % md;
}
struct chash {
    int operator()(pair <int, int> x) const { return x.first* 31 + x.second; }
};
int q;
const int base[] = {229, 233}, mod[] = {417565807, 640663963};
int f_h[2][2 * 1000010], r_h[2][2 * 1000010], len, P[2][2 * 1000010];
char str[2 * 1000010];
vector < pair <int, char > > adj[SZ];
bool mark_cen[SZ];
int parent[SZ], sbtr[SZ], n, centroid, par_cen[SZ];
vector <int> adj_cen[SZ];
void dfs0(int src, int par){
   int i, j, u; sbtr[src] = 1, parent[src] = par;
   for0(i, adj[src].size()){
      u = adj[src][i].first;
      if(u != par){ dfs0(u, src), sbtr[src] += sbtr[u]; }
   }
}
int get_centroid(int src, int par){
   int i, j, u, mx = -1, bg;
   bool is_cen = true;
   for0(i, adj[src].size()){
      u = adj[src][i].first;
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
         u = adj[src][i].first;
         if(!mark_cen[u] && u != par){ get_centroid(src, u, u, src); }
      }
      return;
   }
   for0(i, adj[src].size()){
      u = adj[src][i].first;
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
         u = adj[src][i].first;
         if(u != par && !mark_cen[u]){ get_centroid(src, u, u, src); }
      }
      if(mx != -1 && !mark_cen[root]){ get_centroid(src, root, root, parent[root]); }
   }
   else{ get_centroid(cnn, root, bg, src); }
}
void decompose(){
   int i, j;
   dfs0(0, -1), centroid = get_centroid(0, -1), dfs0(centroid, -1);
   for0(i, n + 2){ mark_cen[i] = false, adj_cen[i].clear(); }
   mark_cen[centroid] = true;
   get_centroid(centroid, centroid, centroid, -1);
   for0(i, n + 2){ mark_cen[i] = false; }
}
gp_hash_table < pair <int, int>, int, chash> mp[SZ], mp_child[SZ];
gp_hash_table < int, pair <int, int > > hash_mp[SZ];
gp_hash_table <int, int> dis_mp[SZ];
void dfs2(int cen, int src, int root, int par, int d, int h0, int h1, bool tick){
   int i, j, sz = adj_cen[src].size(), cnt = 0, nh0, nh1;
   int w, u;
   mp[cen][mpr(h0, h1)]++; dis_mp[cen][src] = d; hash_mp[cen][src] = mpr(h0, h1);
   if(tick){ mp_child[root][mpr(h0, h1)]++; }
   cnt = root == centroid ? 0 : 1;
   for0(i, adj[src].size()){
      u = adj[src][i].first;
      w = adj[src][i].second - 'a' + 1;
      nh0 = add(w, mul(h0, base[0], mod[0]), mod[0]), nh1 = add(w, mul(h1, base[1], mod[1]), mod[1]);
      if(!tick){
         if(u != par && !mark_cen[u]){
            dfs2(cen, u, adj_cen[src][cnt], src, d + 1, nh0, nh1, true); cnt++;
         }
         else if(u == par && !mark_cen[u]){
            dfs2(cen, u, adj_cen[src][sz - 1], src, d + 1, nh0, nh1, true);
         }
      }
      else if(u != par && !mark_cen[u]){
         dfs2(cen, u, root, src, d + 1, nh0, nh1, true);
      }
   }
}
void dfs1(int src, int par){
   int i, j, u; mark_cen[src] = true; par_cen[src] = par;
   mp[src].clear(); dis_mp[src].clear(); hash_mp[src].clear();
   for0(i, adj_cen[src].size()){
      u = adj_cen[src][i];
      if(u != par && !mark_cen[u]){ mp_child[u].clear();}
   }
   dfs2(src, src, src, parent[src], 0, 0, 0, false);
   for0(i, adj_cen[src].size()){
      u = adj_cen[src][i];
      if(u != par && !mark_cen[u]){ dfs1(u, src); }
   }
}
void input(){
   int i, j, u, v;
   char w;
   sii(n, q);
   for0(i, n + 2){ adj[i].clear(); }
   for0(i, n - 1){
      scanf("%d %d %c", &u, &v, &w), u--, v--;
      adj[u].push_back(mpr(v, w)), adj[v].push_back(mpr(u, w));
   }
   decompose();
}
void make_hash(){
   int i, j;
   for0(i, 2){
      for(j = len - 1; j >= 0; j--){
         f_h[i][j] = j == len - 1 ? str[j] - 'a' + 1 :
            add(str[j] - 'a' + 1, mul(f_h[i][j + 1], base[i], mod[i]), mod[i]);
      }
      for(j = 0; j < len; j++){
         r_h[i][j] = j == 0 ? str[j] - 'a' + 1 :
            add(str[j] - 'a' + 1, mul(r_h[i][j - 1], base[i], mod[i]), mod[i]);
      }
   }
//   para(i, 0, len - 1, f_h[0]);
//   para(i, 0, len - 1, r_h[0]);
}
pair <int, int> for_hash(int l, int r){
   if(l > r){ return mpr(0, 0); }
   if(r == len - 1){ return mpr(f_h[0][l], f_h[1][l]); }
   return mpr(add(f_h[0][l], -mul(P[0][r - l + 1], f_h[0][r + 1], mod[0]), mod[0])
              , add(f_h[1][l], -mul(P[1][r - l + 1], f_h[1][r + 1], mod[1]), mod[1]));
}
pair <int, int> rev_hash(int l, int r){
   if(l > r){ return mpr(0, 0); }
   if(l == 0){ return mpr(r_h[0][r], r_h[1][r]); }
   return mpr(add(r_h[0][r], -mul(P[0][r - l + 1], r_h[0][l - 1], mod[0]), mod[0])
              , add(r_h[1][r], -mul(P[1][r - l + 1], r_h[1][l - 1], mod[1]), mod[1]));
}
int query(int u){
   int i, j, p = u, d, prv;
   pair <int, int> f, r;
   int ret = 0;
   for(p = u, prv = u; p != -1; ){
      if(p == u){
         r = rev_hash(0, len - 1);
         ret += mp[p][r];
      }
      else{
         d = dis_mp[p][u];
         if(d <= len){
            f = for_hash(0, d - 1);
            if(f == hash_mp[p][u]){
               r = rev_hash(d, len - 1);
               ret += mp[p][r] - mp_child[prv][r];
            }
         }
      }
      prv = p; p = par_cen[p];
   }
   return ret;
}
void solve(){
   int i, j, u, ret;
   dfs1(centroid, -1);
   for0(i, q){
      scanf("%d %s", &u, &str); u--; len = strlen(str);
      make_hash();
      ret = query(u);
      pi(ret); nl;
   }
   for0(i, n + 2){ adj[i].clear(), adj_cen[i].clear(); }
}
void pre_process(){
   int i, j;
   for0(i, 2){
      for(j = 1, P[i][0] = 1; j <= 2000005; j++){
         P[i][j] = mul(P[i][j - 1], base[i], mod[i]);
      }
   }
//   para(i, 0, 10, P[0]);
}
int main(){
//  freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
   pre_process();
  int cs, ts;
  si(ts);
  for0(cs, ts){
      input();
      printf("Case %d:\n", cs + 1);
      solve();
  }
}




