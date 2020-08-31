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
int n, k, sbtr[SZ], sum[210], dif[SZ][210], sol = 0, fac[SZ], inv[SZ], h[SZ][210], f[210][210];
vector <int> adj[SZ];
void input(){
    int i, j;
    sii(n, k);
    for(i = 0; i < n - 1; i++){
        int u, v; sii(u, v), u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }
}
int bigMod(int v, int p){
    if(p == 0){ return 1; }
    int ret = bigMod(v, p / 2);
    if(p % 2 == 0){ return mul(ret, ret); }
    else{ return mul(ret, mul(ret, v)); }
}
void factorial(){
    int i, j;
    for(i = 1, fac[0] = inv[0] = 1; i < SZ - 1; i++){
        fac[i] = mul(fac[i - 1], i);
        inv[i] = mul(inv[i - 1], bigMod(i, MOD - 2));
    }
}
void H(int src){
    int sz = adj[src].size(), i, j, l, u, x;
    for(i = sz - 1; i >= 0; i--){
        for(u = adj[src][i], j = 0; j <= min(k, sbtr[src] - 1); j++){
            if(i == sz - 1){
                if(j == 0){ h[i][j] = add(1, dif[u][j]); }
                else{ h[i][j] = add(dif[u][j], mul(j, dif[u][j - 1])); }
                continue;
            }
            for(l = 0, h[i][j] = 0; l <= min(sbtr[u], j); l++){
                x = mul(fac[j], mul(inv[l], inv[j - l]));
                if(l == 0){ x = mul(x, add(1, dif[u][0])); }
                else{ x = mul(x, add(dif[u][l], mul(l, dif[u][l - 1]))); }
                x = mul(x, h[i + 1][j - l]);
                h[i][j] = add(h[i][j], x);
            }
        }
    }
}
int F(int u, int v){
    int ret = 0;
    if(v > u){ return 0; }
    if(v == 0){ return 0; }
    if(u == 1){ return 1; }
    if(f[u][v] != -1){ return f[u][v]; }
    ret = add(mul(v, F(u - 1, v)), F(u - 1, v - 1));
    return f[u][v] = ret;
}
bool cmp(int lhs, int rhs){ return sbtr[lhs] < sbtr[rhs]; }
void dfs(int src, int par){
    int i, j, idx = -1, mns, ret, u, x; sbtr[src] = 1, ret = 0;
    for(i = 0; i < adj[src].size(); i++){
        u = adj[src][i];
        if(u == par){ idx = i; break; }
    }
    if(idx != -1){ adj[src].erase(adj[src].begin() + idx); }
    for(i = 0, dif[src][0] = 2, mns = 0; i < adj[src].size(); i++){
        u = adj[src][i];
        dfs(u, src);
        sbtr[src] += sbtr[u];
        dif[src][0] = mul(dif[src][0], add(1, dif[u][0]));
    }
    sort(adj[src].begin(), adj[src].end(), cmp);
    dif[src][0] = add(dif[src][0], -1);
    for(j = 0; j <= k; j++){
        for(i = 0, sum[j] = 0; i < adj[src].size(); i++){
            int u = adj[src][i];
            sum[j] = add(sum[j], dif[u][j]);
        }
    }
    H(src);
    for(i = 1; i <= min(k, sbtr[src] - 1); i++){
        u = adj[src][0];
        x = mul(2, h[0][i]);
        dif[src][i] = x;
        x = add(x , -sum[i]);
        x = add(x, -(mul(i, sum[i - 1])));//check korte hbe
        x = mul(x, F(k, i));
        ret = add(ret, x);
    }
    sol = add(sol, ret);
}
void solve(){
    int i, j;
    mem(f, -1); factorial();
    dfs(0, -1);
    pi(sol); nl;
}
int main(){
//    freopen("input.txt","r",stdin);
//    int ret = F(3, 3);
//    pi(ret); nl;
//    freopen("output.txt", "w", stdout);
    input();
    solve();
}
