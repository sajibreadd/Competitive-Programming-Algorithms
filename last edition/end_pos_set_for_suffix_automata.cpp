inline int add(int _a, int _b, int md){
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
struct state{
    int len, link;
    map <char, int> next;
};
state st[SZ * 2];
int to_state = 0, last, f_occ[SZ * 2], d[2 * SZ], sbtr[2 * SZ], vrtx[2 * SZ];
int t = 0;
vector <int> adj[2 * SZ];
void sa_init(){
    to_state = 0, st[0].len = 0, st[0].link = -1;
    to_state++, last = 0;
}
void sa_extend(char c){
    int cur = to_state++;
    st[cur].len = st[last].len + 1, f_occ[cur] = st[cur].len - 1;
    st[cur].next.clear();
    int p = last;
    while(p != -1 && st[p].next.find(c) == st[p].next.end()){
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
            f_occ[clone] = f_occ[q];
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    } last = cur;
}
int n; ll mx_up, mx_dn;
char str[SZ];
void build(){
    int i, j, u, v;
    sa_init();
    for0(i, n){ sa_extend(str[i]); }
    for0(i, to_state){
        u = i, v = st[i].link;
        if(v != -1){ adj[v].push_back(u); }
    }
}
void input(){
    int i, j;
    ss(str), n = strlen(str);
}
void dfs(int src){
    int i, j, u;
    vrtx[t++] = src, d[src] = t - 1, sbtr[src] = 1;
    for0(i, adj[src].size()){
        u = adj[src][i];
        dfs(u), sbtr[src] += sbtr[u];
    }
}
set <int> end_pos;
inline void update_max(ll up, ll dn){
    ll g = __gcd(up, dn); up /= g, dn /= g;
    if(mx_up * dn <= up * mx_dn){
        mx_up = up, mx_dn = dn;
    }
}
inline void update(int src, int pos){
    ll up, dn;
    if(end_pos.empty()){ return; }
    std :: set <int> :: iterator it;
    it = end_pos.upper_bound(pos);
    if(it == end_pos.end()){
        --it;
        if(abs(pos - *it) >= st[src].len){
            up = (ll)abs(pos - *it) + (ll)st[src].len;
            dn = (ll)abs(pos - *it);
            update_max((ll)up, (ll)dn);
        }
        return;
    }
    if(*it - pos >= st[src].len){
        up = (ll)abs(*it - pos) + (ll)st[src].len;
        dn = (ll)abs(*it - pos);
        update_max((ll)up, (ll)dn);
    }
    if(it != end_pos.begin()){
        --it;
        if(abs(pos - *it) >= st[src].len){
            up = (ll)abs(pos - *it) + (ll)st[src].len;
            dn = (ll)abs(pos - *it);
            update_max((ll)up, (ll)dn);
        }
    }
}
void dsu(int src, bool keep){
    int i, j, mx = -1, bg = -1, u, v;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(sbtr[u] > mx){
            mx = sbtr[u], bg = u;
        }
    }
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != bg){
            dsu(u, false);
        }
    }
    if(bg != -1){ dsu(bg, true); }
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != bg){
            for(j = d[u]; j <= d[u] + sbtr[u] - 1; j++){
                v = vrtx[j];
                if(f_occ[v] + 1 - st[v].len == 0){
                    update(src, f_occ[v]);
                    end_pos.insert(f_occ[v]);
                }
            }
        }
    }
    if(f_occ[src] + 1 - st[src].len == 0){
        update(src, f_occ[src]), end_pos.insert(f_occ[src]);
    }
    if(!keep){ end_pos.clear(); }
}
int h[2][SZ], base[] = {47, 31}, P[2][SZ], mod[] = {MOD, MOD + 2};
void make_hash(){
    int i, j;
    for0(i, 2){
        for(j = 1, P[i][0] = 1; j <= SZ - 2; j++){
            P[i][j] = mul(P[i][j - 1], base[i], mod[i]);
        }
    }
    for0(i, 2){
        for(j = n - 1, h[i][n] = 0; j >= 0; j--){
            h[i][j] = add(str[j] - 'a' + 1, mul(base[i], h[i][j + 1], mod[i]), mod[i]);
        }
    }
}
inline int get_hash(int l, int r, int idx){
    return add(h[idx][l], -mul(h[idx][r + 1], P[idx][r - l + 1], mod[idx]), mod[idx]);
}
int lcp(int l1, int r1, int l2, int r2){
    if(l1 > r1 || l2 > r2){ return 0; }
    int lo = 0, hi = min(r1 - l1 + 1, r2 - l2 + 1), mid;
    int f0, f1, g0, g1;
    while(lo < hi){
        mid = (lo + hi + 1) >> 1;
        f0 = get_hash(l1, l1 + mid - 1, 0);
        f1 = get_hash(l1, l1 + mid - 1, 1);
        g0 = get_hash(l2, l2 + mid - 1, 0);
        g1 = get_hash(l2, l2 + mid - 1, 1);
        if(f0 == g0 && f1 == g1){ lo = mid; }
        else{ hi = mid - 1; }
    }
    return lo;
}
int lcs(int l1, int r1, int l2, int r2){
    if(l1 > r1 && l2 > r2){ return 0; }
    int lo = 0, hi = min(r1 - l1 + 1, r2 - l2 + 1), mid;
    int f0, f1, g0, g1;
    while(lo < hi){
        mid = (lo + hi + 1) >> 1;
        f0 = get_hash(r1 - mid + 1, r1, 0);
        f1 = get_hash(r1 - mid + 1, r1, 1);
        g0 = get_hash(r2 - mid + 1, r2, 0);
        g1 = get_hash(r2 - mid + 1, r2, 1);
        if(f0 == g0 && f1 == g1){ lo = mid; }
        else{ hi = mid - 1; }
    }
    return lo;
}
pair <int, int > vec[SZ];
void solve(){
    int i, j, cnt, k;
    build();
    t = 0, dfs(0);
    mx_up = -INF, mx_dn = 1; dsu(0, false);
    make_hash();
    for(i = 1; i <= n; i++){
        for(j = 0, cnt = 0; j + i - 1 < n; j += i){
            int h0 = get_hash(j, j + i - 1, 0);
            int h1 = get_hash(j, j + i - 1, 1);
            vec[cnt++] = mpr(h0, h1);
        }
        for(j = 0; j < cnt; j = k){
            for(k = j; k < cnt && vec[k] == vec[j]; k++){}
            int x = lcs(0, j * i - 1, j * i, j * i + i - 1);
            int y = lcp(k * i, n - 1, j * i, j * i + i - 1);
            ll up = (ll)x + (ll)y + (ll)(k - j) * (ll)i;
            ll dn = i;
            update_max(up, dn);
        }
    }
    printf("%lld/%lld\n", mx_up, mx_dn);
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);

    input();
    solve();
}
