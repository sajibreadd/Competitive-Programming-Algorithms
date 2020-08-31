#include <bits/stdc++.h>
using namespace std;
bool Q;
struct Line {
    mutable long long m, c, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : m < o.m;
    }
};
struct LineContainer : multiset<Line> {
    const long long inf = LLONG_MAX;
    long long div(long long a, long long b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = LLONG_MAX; return false; }
        if (x->m == y->m) x->p = x->c > y->c ? inf : -inf;
        else x->p = div(y->c - x->c, x->m - y->m);
        return x->p >= y->p;
    }
    void add(long long m, long long c) {
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    long long query(long long x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.m * x + l.c;
    }
};
LineContainer cur;
int main(){
    std::multiset <Line>::iterator it;
    Q = false;
    cur.clear();
    cur.add(6, 7);
    cur.add(5, 10);
    cur.add(4, 100);
    cur.add(3, 4);
    for(it = cur.begin(); it != cur.end(); ++it){
        printf("%lld %lld %lld\n", it->m, it->c, it->p);
    }
    printf("%lld\n", cur.query(2));
}
