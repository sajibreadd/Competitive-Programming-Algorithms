//catalan path
int toPath(point from,point to){
    int total=mul(fac[to.x-from.x+to.y-from.y],invFac[to.x-from.x]);
    total=mul(total,invFac[to.y-from.y]);
    if(min(from.x-c,b)<to.y){
        int mns;
        int hor=to.x-from.x;
        int ver=to.y-from.y;
        point des;
        des.x=ver-min(from.x-c,b)+from.y-1+from.x;
        des.y=min(from.x-c,b)+1+hor;
        mns=mul(fac[des.x-from.x+des.y-from.y],invFac[des.x-from.x]);
        mns=mul(mns,invFac[des.y-from.y]);
        total=add(total,(-1)*mns);
    }
    return total;
}
//n^2longn solution for chaining
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
int big_mod(int v, int p){
    if(p == 0){ return 1; }
    int ret = big_mod(v, p / 2);
    if(p % 2 == 0){ return mul(ret, ret); }
    else{ return mul(ret, mul(ret, v)); }
}
int n, m, dp[2010][2010], fac[2010], inv_fac[2010], inv[2010];
void input(){
    int i, j;
    sii(n, m);
}
void solve(){
    int i, j, x, k, y;
    for(i = 1; i <= n; i++){
        for(j = i, dp[0][i + 1] = 1; j >= 1; j--){
            for(k = 0, x = 1; k * j <= i; k++){
                y = mul(x, inv_fac[k]);
                dp[i][j] = add(dp[i][j], mul(y, dp[i - k * j][j + 1]));
                x = mul(x, mul(inv[j], j % 2 == 0 ? mul(m, m) : m));
            }
        }
    }
    pi(mul(dp[n][1], fac[n])); nl;
}
void pre_process(){
    int i, j;
    for(i = 1, fac[i - 1] = 1; i <= 2005; i++){
        fac[i] = mul(fac[i - 1], i);
    }
    for(i = 2004, inv_fac[i + 1] = big_mod(fac[i + 1], MOD - 2); i >= 0; i--){
        inv_fac[i] = mul(inv_fac[i + 1], i + 1);
    }
    for(i = 2005; i >= 1; i--){
        inv[i] = mul(inv_fac[i], fac[i - 1]);
    }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    pre_process();
    input();
    solve();
}

