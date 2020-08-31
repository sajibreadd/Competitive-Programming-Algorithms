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
int n, ara[SZ], sccCnt = 0, sccRoot[SZ], sccNo[SZ], rootNo[SZ], sbtr[SZ], ht[SZ], q, global[SZ], position[SZ], sol[SZ];
const int thresh = 200005;
bool inCycle[SZ];
vector <int> adj[SZ], rev[SZ], scc[SZ], cum[SZ];
vector <int> topo, treeRoot, qlist[SZ], vrtx;
pair <ll, int> query[SZ];
bool vis[SZ];
void input(){
    int i, j;
    si(n);
    for1(i, n){
        si(ara[i]);
        if(ara[i] == i){ inCycle[ara[i]] = true; }
        adj[ara[i]].push_back(i); rev[i].push_back(ara[i]);
    }
//    ppvec(i, j, n + 1, adj);
}
void dfs0(int src){
    int i, j; vis[src] = true;
    for0(i, adj[src].size()){
        int u = adj[src][i];
        if(!vis[u]){ dfs0(u); }
    } topo.push_back(src);
}
void dfs1(int src){
    int i, j; vis[src] = true; scc[sccCnt].push_back(src);
    sccNo[src] = sccCnt;
    for0(i, rev[src].size()){
        int u = rev[src][i];
        if(!vis[u]){ dfs1(u); }
    }
}
void dfs2(int src, int rt){
    int i, j; vis[src] = true; sbtr[src] = 1;
    rootNo[src] = rt;
    vrtx.push_back(src);
    for0(i, adj[src].size()){
        int u = adj[src][i];
        if(!vis[u]){ dfs2(u, rt), sbtr[src] += sbtr[u]; }
    }
}
void dfs3(int src, int rt, int d, int len, int idx){
    int i, j; vis[src] = true; ht[src] = d;
    cum[idx][ht[src]]++;
    for0(i, adj[src].size()){
        int u = adj[src][i];
        if(!vis[u]){
            if(inCycle[u]){ dfs3(u, u, d + 1, len, idx); }
            else{ dfs3(u, rt, d + 1, len, idx); }
        }
    }
}

void dsu(int src, int par, bool keep){
    int i, j, u, bg = -1, mx = -1, v;
    ll d;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par && u != rootNo[src]){
            if(sbtr[u] > mx){ mx = sbtr[u], bg = u; }
        }
    }
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par && u != rootNo[src] && u != bg){
            dsu(u, src, false);
        }
    }
    if(mx != -1){ dsu(bg, src, true); }
    global[ht[src]]++;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(u != par && u != rootNo[src] && u != bg){
            for(j = position[u]; j <= position[u] + sbtr[u] - 1; j++){
                v = vrtx[j];
                global[ht[v]]++;
            }
        }
    }
    for0(i, qlist[src].size()){
        int idx = qlist[src][i];
        d = query[idx].first;
        if((ll)ht[src] + d <= (ll)thresh){
            sol[idx] += global[(ll)ht[src] + d];
        }
    }
    if(!keep){
        for(j = position[src]; j <= position[src] + sbtr[src] - 1; j++){
            v = vrtx[j];
            global[ht[v]]--;
        }
    }
}
void solve(){
    int i, j, u, len, r, dis, sz;
    ll d;
    for(i = 1; i <= n; i++){
        if(!vis[i]){ dfs0(i); }
    }
//    pvec(i, topo);
    reverse(topo.begin(), topo.end());
    for(i = 1; i <= n; i++){ vis[i] = false; }
    for(i = 0, sccCnt = 0; i < topo.size(); i++){
        if(!vis[topo[i]]){
            dfs1(topo[i]);
            sccRoot[sccCnt] = topo[i];
            sccCnt++;
        }
    }
    for0(i, sccCnt){
        if(scc[i].size() >= 2){
            for0(j, scc[i].size()){
                inCycle[scc[i][j]] = true;
            }
        }
    }
    for(i = 1; i <= n; i++){ vis[i] = false; }
    for(i = 0; i < sccCnt; i++){
        if(scc[i].size() >= 2 || (scc[i].size() == 1 && inCycle[scc[i][0]])){
            treeRoot.push_back(sccRoot[i]);
            dfs2(sccRoot[i], sccRoot[i]);
        }
        else if(scc[i].size() == 1 && rev[scc[i][0]].size() == 0){
            treeRoot.push_back(scc[i][0]);
            dfs2(scc[i][0], scc[i][0]);
        }
    }
    for0(i, vrtx.size()){
        u = vrtx[i], position[u] = i;
    }
    for(i = 1; i <= n; i++){ vis[i] = false; }
    for(i = 0; i < treeRoot.size(); i++){
        u = treeRoot[i];
        if(inCycle[u]){
            cum[u].resize(sbtr[u] + 1);
            len = scc[sccNo[u]].size();
            dfs3(u, u, 0, len, u);
            for(j = 0; j < cum[u].size(); j++){
                cum[u][j] = j - len < 0 ? cum[u][j] : cum[u][j] + cum[u][j - len];
            }
        }
    }
    si(q);
    for0(i, q){
        scanf("%lld  %d", &query[i].first, &query[i].second);
        qlist[query[i].second].push_back(i);
        u = query[i].second; d = query[i].first;
//        pi(u); nl;
        if(inCycle[u]){
            r = rootNo[u];
            len = scc[sccNo[r]].size();
            dis = len - ht[u];
            d -= (ll)dis; sz = cum[r].size();
            if(d >= sz){
                d = d - ((d - (ll)sz + (ll)len) / (ll)len) * (ll)len;
            }
            if(d < 0){ continue; }
            sol[i] += cum[r][d];
        }
    }
    for0(i, treeRoot.size()){
        u = treeRoot[i];
        dsu(u, -1, false);
    }
    for0(i, q){
        pi(sol[i]); nl;
    }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    input();
    solve();
}
