/// Complexity = nb * N + bs * Q
/// Better to keep input array 0 based

int bs;///block size
int ara[MAXN] , cnt[MAXV] , res[MAXQ];
int ans;

struct data{
    int l,r,id,bn;
    inline data() {}
    inline data(int _l, int _r, int _id){
        l = _l , r = _r , id = _id;
        bn = l / bs;
    }

    inline bool operator < (const data& other) const{
        if (bn != other.bn) return (bn < other.bn);
        return ((bn & 1) ? (r < other.r) : (r > other.r));
    }

} query[MAXQ];

void Add(int id){
    cnt[ara[id]]++;
    ///update ans
}

void Remove(int id){
    cnt[ara[id]]--;
    ///update ans
}

void Mo(int q){
    sort( query , query + q );
    int L = 0, R = 0,l,r;
    ans = 0;
    Add(0);
    for(int i=0; i<q; i++) {
        l = query[i].l;
        r = query[i].r;

        while(L>l) Add(--L);
        while(R<r) Add(++R);

        while(L<l) Remove(L++);
        while(R>r) Remove(R--);

        res[query[i].id] = ans;
    }
}

