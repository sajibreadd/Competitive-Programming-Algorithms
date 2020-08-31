const int N = 1 << 20, mod = 786433, g = 10;
int rev[N], w[N], inv_n;
int bigMod(int v, int p){
    if(p == 0){ return 1; }
    int ret = bigMod(v, p / 2);
    if(p % 2 == 0){ return mul(ret, ret); }
    else{ return mul(ret, mul(ret, v)); }
}
void prepare(int &n) {
	int sz = 31 - __builtin_clz(n); sz = abs(sz);
	int r = bigMod(g, (mod - 1) / n);
	inv_n = bigMod(n, mod - 2);
	w[0] = w[n] = 1;
	for(int i = 1; i < n; ++i) w[i] = (ll)w[i - 1] * r % mod;
	for(int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
}
void ntt(int *a, int n, int dir) {
	for(int i = 1; i < n - 1; ++i)
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int m = 2; m <= n; m <<= 1) {
		for(int i = 0; i < n; i += m) {
			for(int j = 0; j < (m >> 1); ++j) {
				int &u = a[i + j], &v = a[i + j + (m >> 1)];
				int t = (ll)v * w[dir ? n - n / m * j : n / m * j] % mod;
				v = u - t < 0 ? u - t + mod : u - t;
			 	u = u + t >= mod ? u + t - mod : u + t;
			}
		}
	} if(dir) for(int i = 0; i < n; ++i) a[i] = (ll)a[i] * inv_n % mod;
}
int f_a[N], f_b[N];
vector <int> multiply(vector <int> a, vector <int> b){
    int sz = 1, na = (int)(a.size()), nb = (int)(b.size());
    while(sz < na + nb - 1){ sz <<= 1; }
    prepare(sz);
    for (int i = 0; i < sz; ++i) f_a[i] = i < na ? a[i] : 0;
    for (int i = 0; i < sz; ++i) f_b[i] = i < nb ? b[i] : 0;
    ntt(f_a, sz, 0); ntt(f_b, sz, 0);
    for (int i = 0; i < sz; ++i) f_a[i] = (ll) f_a[i] * f_b[i] % MOD;
    ntt(f_a, sz, 1); return vector <int> (f_a, f_a + sz);
}
// primitive root, finding the number with order p-1
int primitive_root(int p) {
	vector<int> factor;
	int tmp = p - 1;
	for(int i = 2; i * i <= tmp; ++i) {
		if (tmp % i == 0) {
			factor.push_back(i);
			while (tmp % i == 0) tmp /= i;
		}
	}
	if(tmp != 1) factor.push_back(tmp);
	for(int root = 1; ; ++root) {
		bool flag = true;
		for(int i = 0; i < factor.size(); ++i) {
			if(Pow(root, (p - 1) / factor[i], p) == 1) {
				flag = false;
				break;
			}
		}
		if (flag) return root;
	}
}
