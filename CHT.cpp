struct CHT{
	vector < pair <ll, ll > > vec; 
	void ini(){ vec.clear(); }
	bool check(pair <ll, ll> a, pair <ll, ll> b, pair <ll, ll> c){
		ll ua, va, ub, vb; 
		ua = b.yy - a.yy; 
		va = a.xx - b.xx; 
		ub = a.yy - c.yy; 
		vb = c.xx - a.xx; 
        // assert(va > 0 && vb > 0); 
        return ua * vb >= ub * va; 
        // maximization--ascending order--ua * vb >= ub * va; 
        // maximization--dscending order--ua * vb <= ub * va; 
        // minimization--ascending order--ua * vb <= ub * va; 
        // minimization--dscending order--ua * vb >= ub * va; 
	}
	void add_line(ll m, ll c){
		int len = vec.size(); 
		pair <ll, ll> line = mpr(m, c); 
		while(len >= 2 && check(vec[len - 1], vec[len - 2], line)){
			vec.pop_back(); --len; 
		}
        if(!vec.empty() && vec.back().xx == m){
            if(c > vec.back().yy) vec.pop_back(), vec.push_back(mpr(m, c)); 
            // for maximization c > vec.back().yy
            // for minimization c < vec.back().yy
        }
        else vec.push_back(mpr(m, c)); 
	}
	bool ok(int pos, ll x){
		ll u = vec[pos - 1].yy - vec[pos].yy; 
		ll v = vec[pos].xx - vec[pos - 1].xx; 
        // assert(v > 0); 
        // maximization--ascending order--u <= v * x; 
        // maximization--dscending order--u >= v * x; 
        // minimization--ascending order--u >= v * x; 
        // minimization--dscending order--u <= v * x; 
        return u <= v * x; 
	}
	ll query(ll x){
		if(vec.empty()) return LLONG_MAX; 
		if(vec.size() == 1) return vec[0].xx * x + vec[0].yy; 
		int lo = 0, hi = (int) vec.size() - 1; 
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1; 
			if(ok(mid, x)) lo = mid;
			else hi = mid - 1;  
		}
		return vec[lo].xx * x + vec[lo].yy; 
	}
}; 