int n, ara[SZ], q, nxt[SZ], hole[SZ], inside[SZ];
int sqn;
void input(){
    int i, j;
    sii(n, q);
    for0(i, n){si(ara[i]);}
    sqn = sqrt(n) + 1;
}
void solve(){
    int i, j, ret = 0, last;
    for(i = 0; i <= n / sqn; i++){
        for(j = min(n - 1, (i + 1) * sqn - 1); j >= i * sqn; j--){
            if(j + ara[j] > min(n - 1, (i + 1) * sqn - 1)){
                nxt[j] = j + ara[j];
                inside[j] = j;
                hole[j] = 1;
            }
            else{
                nxt[j] = nxt[j + ara[j]];
                inside[j] = inside[j + ara[j]];
                hole[j] = 1 + hole[j + ara[j]];
            }
        }
    }
    for0(i, q){
        int t;
        si(t);
        if(t == 0){
            int idx, v;
            sii(idx, v); idx--;
            ara[idx] = v;
            for(j = min(n - 1, ((idx / sqn) + 1) * sqn - 1); j >= (idx / sqn) * sqn; j--){
                if(j + ara[j] > min(n - 1, ((idx / sqn) + 1) * sqn - 1)){
                    inside[j] = j;
                    nxt[j] = j + ara[j];
                    hole[j] = 1;
                }
                else{
                    nxt[j] = nxt[j + ara[j]];
                    inside[j] = inside[j + ara[j]];
                    hole[j] = 1 + hole[j + ara[j]];
                }
            }
        }
        else{
            int idx;
            si(idx); idx--;
            for(ret = 0 ;idx < n;){
                last = inside[idx];
                ret += hole[idx];
                idx = nxt[idx];
            }
            pii(last + 1, ret);NL;
        }
    }
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
}
