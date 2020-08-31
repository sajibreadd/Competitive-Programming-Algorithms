int n, G[SZ], F[SZ], dp[SZ];
bool vis[SZ];
vector <int> segmentation(int l1, int r1, int l2, int r2){
    int i, j;
    vector <int> a, b;
    a.resize(r1 - l1 + 1); b.resize(r2 - l2 + 1);
    for(i = l1, j = 0; i <= n && i <= r1; i++, j++){
        a[j] = F[i];
    }
    for(i = l2, j = 0; i <= n && i <= r2; i++, j++){
        b[j] = G[i];
    }
    return multiply(a, b);
}
void contribute(int offst, vector <int> &poly){
    int i, j;
    for(j = 0; j < poly.size() && j + offst <= n; j++){
        F[j + offst] = add(F[j + offst], poly[j]);
    }
}
void solve(){
    int i, j, l, ret;
    F[0] = 1;
    for(i = 0; i <= n; i++){ F[i] = G[i]; }
    for(i = 0; i <= n; i++){
        for(j = 0; (1 << j) <= i + 1; j++){
            if((i + 1) % (1 << j) == 0){
                vector <int> a = segmentation(i - (1 << j) + 1, i, 1 << j, (1 << j) + (1 << j) - 1);
                int offst = (1 << j) * (i / (1 << j) + 1);
                contribute(offst, a);
//                cout << "i-->" << i << " " << "j-->" << j << " " << offst; nl;
                para(l, 0, n, F);
            }
        }
    } //nl;
    dp[0] = 1;
    for(i = 0; i <= n; i++){
        ret = brute(i);
    }
    para(i, 0, n, dp);
    para(i, 0, n, F);
}
