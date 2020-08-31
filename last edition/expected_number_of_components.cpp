//First we consider how to calculate E(X).
//
//The number of connected components equals to the number of nodes
//minus the number of edges and then add the number of rings in it.
//So we can calculate the possibility of removing one node,
//one edge or one single ring.
//
//Then we can split the variance, it is equals to E(X2)−2∗E(X)2+E(X)2=E(X2)−E(X)2.
//Then we can again to split X2.
//Let the number nodes equal to a, the number edges equal to b,
//the number rings equal to c.
//Then X2=(a−b+c)2=a2+b2+c2−2ab−2bc+2ac.
//We can find there is contribution between a pair of nodes, edges, rings
//(the two may be the same) and between a node and an edge,
//a node and a ring, an edge and a ring. Then we can calculate the possibility of
//such pair that the elements in it remains at the same time.
//The answer is the same when the pair is a ring and a node on it,
//or when it is a ring and a node not on it,
//or an edge with one of its end point ...
//If we consider all the situation of intersection and not intersection,
//we can get a liner algorithm. But the Time Complexity is O(nlogn)
//since we need to calculate the multiplicative inverse of modulo.
int big_mod(int v, int p){
    if(p == 0){ return 1; }
    int ret = big_mod(v, p / 2);
    if(p % 2 == 0){ return mul(ret, ret); }
    return mul(ret, mul(ret, v));
}
int n, m, pwr[2 * SZ], inv_pwr[2 * SZ];
vector <int> adj[SZ];
bool vis[SZ], is_art[SZ];
int Time, low[SZ], dis[SZ], bcc_cnt;
vector <int> bcc[SZ], art_vec[SZ];
stack <int> S;
void pop_bcc(int s, int u){
    is_art[s] = true;
    bcc[bcc_cnt].push_back(s);
    while(true){
        bcc[bcc_cnt].push_back(S.top());
        if(S.top() == u){ S.pop(); break; }
        S.pop();
    }
    bcc_cnt++;
    if(bcc[bcc_cnt - 1].size() <= 2){
        bcc[bcc_cnt - 1].clear();
        bcc_cnt--;
    }
}
void find_bcc(int src, int par){
    S.push(src);
    int i, u, child = 0; vis[src] = true, Time++, dis[src] = low[src] = Time;
    for0(i, adj[src].size()){
        u = adj[src][i];
        if(!vis[u]){
            child++, find_bcc(u, src);
            low[src] = min(low[src], low[u]);
            if(par != -1 && low[u] >= dis[src]){ pop_bcc(src, u); }
            else if(par == -1){
                if(child > 1){ pop_bcc(src, u); }
            }
        } else if(par != u){ low[src] = min(low[src], dis[u]); }
    } if(par == -1 && child > 1){ is_art[src] = true; }
}
void process_bcc(){
    int i, j;
    bool f;
    bcc_cnt = 0;
    for0(i, n){
        if(!vis[i]){
            Time = 0;
            find_bcc(i, -1);
            f = false;
            while(!S.empty()){
                f = true;
                bcc[bcc_cnt].push_back(S.top());
                S.pop();
            } if(f){
                bcc_cnt++;
                if(bcc[bcc_cnt - 1].size() <= 2){
                    bcc[bcc_cnt - 1].clear();
                    bcc_cnt--;
                }
            }
        }
    }
}
void input(){
    int i, j;
    sii(n, m);
    for0(i, m){
        int u, v;
        sii(u, v), u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }
}
inline int comb(int a){
    return mul(a, a - 1);
}
void solve(){
    int i, j, sol = 0, sz, baki = 0, sum = 0, sz1;
    process_bcc();
    //a
    int a = mul(n, inv_pwr[1]);
    //b
    int b = mul(m, inv_pwr[2]);
    //c
    int c = 0;
    for0(i, bcc_cnt){
        sz = bcc[i].size();
        c = add(c, inv_pwr[sz]);
    }
    //a^2;
    int a_2 = mul(comb(n), inv_pwr[2]);
    a_2 = add(a_2, mul(n, inv_pwr[1]));
    //b^2
    int b_2 = 0;
    for0(i, n){
        sz = adj[i].size();
        b_2 = add(b_2, mul(comb(sz), inv_pwr[3]));
        b_2 = add(b_2, -mul(comb(sz), inv_pwr[4]));
    }
    b_2 = add(b_2, mul(comb(m), inv_pwr[4]));
    b_2 = add(b_2, mul(m, inv_pwr[2]));
    //c^2
    int c_2 = 0;
    for0(i, bcc_cnt){
        for0(j, bcc[i].size()){
            if(is_art[bcc[i][j]]){
                art_vec[bcc[i][j]].push_back(i);
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0, sum = 0; j < art_vec[i].size(); j++){
            sz = bcc[art_vec[i][j]].size();
            sum = add(sum, inv_pwr[sz]);
        }
        for0(j, art_vec[i].size()){
            sz = bcc[art_vec[i][j]].size();
            c_2 = add(c_2, mul(add(sum, -inv_pwr[sz]), inv_pwr[sz - 1]));
            c_2 = add(c_2, -mul(add(sum, -inv_pwr[sz]), inv_pwr[sz]));
        }
    }
    for(i = 0, sum = 0; i < bcc_cnt; i++){
        sz = bcc[i].size();
        sum = add(sum, inv_pwr[sz]);
    }
    for0(i, bcc_cnt){
        sz = bcc[i].size();
        c_2 = add(c_2, mul(add(sum, -inv_pwr[sz]), inv_pwr[sz]));
        c_2 = add(c_2, inv_pwr[sz]);
    }
    //ab
    int ab = 0;
    ab = add(ab, mul(mul(2, m), inv_pwr[2]));
    ab = add(ab, mul(mul(m, n - 2), inv_pwr[3]));
    //bc
    int bc = 0;
    for0(i, bcc_cnt){
        sz = bcc[i].size();
        bc = add(bc, mul(sz, inv_pwr[sz]));
        bc = add(bc, -mul(sz, inv_pwr[sz + 2]));
        bc = add(bc, mul(m, inv_pwr[sz + 2]));
        for0(j, bcc[i].size()){
            sz1 = adj[bcc[i][j]].size();
            sz1 = add(sz1, -2);
            bc = add(bc, mul(sz1, inv_pwr[sz + 1]));
            bc = add(bc, -mul(sz1, inv_pwr[sz + 2]));
        }
    }
    //ac
    int ca = 0;
    for0(i, bcc_cnt){
        sz = bcc[i].size();
        ca = add(ca, mul(sz, inv_pwr[sz]));
        ca = add(ca, -mul(sz, inv_pwr[sz + 1]));
        ca = add(ca, mul(n, inv_pwr[sz + 1]));
    }
    int e_x = add(a, add(-b, c));
    sol = 0;
    sol = add(sol, -mul(e_x, e_x));
    sol = add(sol, add(a_2, add(b_2, c_2)));
    sol = add(sol, -mul(2, ab));
    sol = add(sol, -mul(2, bc));
    sol = add(sol, mul(2, ca));
    pi(sol); nl;
}
void pre_process(){
    int i, j, inv_2 = big_mod(2, MOD - 2);
    for(i = 1, pwr[0] = 1, inv_pwr[0] = 1; i < 2 * SZ - 2; i++){
        pwr[i] = mul(pwr[i - 1], 2);
        inv_pwr[i] = mul(inv_pwr[i - 1], inv_2);
    }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    pre_process();
    input();
    solve();
}
