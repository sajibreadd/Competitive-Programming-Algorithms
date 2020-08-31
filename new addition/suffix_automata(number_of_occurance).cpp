/********suffix automata*********/
int add(int _a, int _b, int md){
   if(_a < 0){ _a += md; }
   if(_b < 0){ _b += md; }
   if(_a + _b >= md){ return _a + _b - md; }
   return _a + _b;
}
int mul(int _a, int _b, int md){
   if(_a < 0){ _a += md; }
   if(_b < 0){ _b += md; }
   return ((ll)((ll)_a * (ll)_b)) % md;
}
vector <int> adj[SZ];
struct state{
    int len, link;
    gp_hash_table <char, int> next;
};
state st[SZ * 2];
int to_state = 0, last, occ[SZ * 2];
//occ should be initialized for every testcase
void sa_init(){
   to_state = 0;
   st[0].len = 0;
   st[0].link = -1;
   to_state++;
   last = 0;
}
void sa_extend(char c) {
    int cur = to_state++;
    st[cur].len = st[last].len + 1; occ[cur] = 1;
    st[cur].next.clear(); adj[cur].clear();
    int p = last;
    while (p != -1 && st[p].next.find(c) == st[p].next.end()) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if(p == -1){ st[cur].link = 0; }
    else{
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len){ st[cur].link = q; }
        else{
            int clone = to_state++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            occ[clone] = 0; adj[clone].clear();
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
char str[SZ];
int q, A, B, n, q_len;
char q_str[SZ];
const int magic = 300;
void input(){
   int i, j;
   ss(str); n = strlen(str);
   siii(q, A, B);
}
void dfs(int src){
   int i, j, u;
   for0(i, adj[src].size()){
      u = adj[src][i];
      dfs(u);
      occ[src] += occ[u];
   }
}
void rebuild(int offst){
   int i, j, u, v;
   sa_init();
   for0(i, n + offst){ sa_extend(str[i]); }
   for0(i, to_state){
      u = i, v = st[i].link;
      if(v != -1){ adj[v].push_back(u); }
   }
   dfs(0);
}
int prefix[SZ];
int do_brute(int from, int to){
   int i, j, cnt = 0, k;
   if(to - from + 1 < q_len){ return 0; }
   for(k = -1, i = 1, prefix[0] = 0; i < q_len; i++){
      while(k >= 0 && q_str[k + 1] != q_str[i]){ k = prefix[k] - 1; }
      if(q_str[k + 1] == q_str[i]){ k++; }
      prefix[i] = k + 1;
   }
   for(k = -1, i = from; i <= to; i++){
      while(k >= 0 && q_str[k + 1] != str[i]){ k = prefix[k] - 1; }
      if(q_str[k + 1] == str[i]){ k++; }
      if(k + 1 == q_len){ cnt++; k = prefix[k] - 1; }
   }
   return cnt;
}
int occurance(){
   int i, j, t = 0;
   for(i = 0; i < q_len; i++){
      if(st[t].next.find(q_str[i]) != st[t].next.end()){ t = st[t].next[q_str[i]]; }
      else{ return 0; }
   }
   return occ[t];
}
void solve(){
   int i, j, v, ret = 0;
   rebuild(0);
   for(i = 0; i < q; i++){
      ss(q_str); q_len = strlen(q_str);
      ret = 0; ret += do_brute(max(n + (i / magic) * magic - q_len + 1, 0), n + i - 1);
      ret += occurance();
      pi(ret); nl;
      v = add(B, mul(A, ret, 26), 26) + 'a';
      str[n + i] = (char)v;
      if((i + 1) % magic == 0){ rebuild(i + 1); }
   }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
   input();
   solve();
}
