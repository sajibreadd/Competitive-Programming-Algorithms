#include <bits/stdtr1c++.h>
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%ch",&ch)
#define ps(a) printf("%s",a)
#define newLine() printf("\n")
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define pd(a) printf("%lf",a)
#define pdd(a,b) printf("%lf %lf",a,b)
#define pddd(a,b,c) printf("%lf %lf %lf",a,b,c)
#define pch(c) printf("%ch",c)
#define debug1(str,a) printf("%s=%d\n",str,a)
#define debug2(str1,str2,a,b) printf("%s=%d %s=%d\n",str1,a,str2,b)
#define debug3(str1,str2,str3,a,b,c) printf("%s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c)
#define debug4(str1,str2,str3,str4,a,b,c,d) printf("%s=%d %s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c,str4,d)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define NL puts("")
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf %lf",&a,&b)
#define sddd(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define SP printf(" ")
#define LL long long int
#define ULL unsigned long long int
#define MOD 1000000007
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
#define eps 1e-9
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n  (1<<pos))
#define para(i,a,b,ara)\
for(i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    cout<<ara[i];\
}\
printf("\n");
#define pvec(i,vec)\
for(i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    cout<<vec[i];\
}\
printf("\n");
#define ppara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    for(j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        cout<<ara[i][j];\
    }\
    printf("\n");\
}
#define ppstructara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j];printf("\n");\
    }\
}
#define ppvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        cout<<vec[i][j];\
    }\
    printf("\n");\
}
#define ppstructvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j];printf("\n");\
    }\
}
#define sara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}
#define pstructara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i];NL;\
}
#define pstructvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i];NL;\
}
#define pstructstl(stl,x)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    x=*it;\
    cout<<x;NL;\
}\
NL;
#define pstl(stl)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    if(it!=stl.begin()){SP;}\
    pi(*it);\
}\
NL;
#define ppairvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i].first;SP;cout<<vec[i].second;printf("\n");\
}
#define ppairara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i].first;SP;cout<<ara[i].second;printf("\n");\
}
#define pppairvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;SP;cout<<vec[i][j].second;NL;\
    }\
}
#define pppairara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;NL;\
    }\
}
#define SZ 100010
using namespace std;
namespace rho{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    const int MAXP = 1000010;
    const int BASE[] = {2, 450775, 1795265022, 9780504, 28178, 9375, 325};

    LL seq[MAXP];
    int primes[MAXP], spf[MAXP];

    inline LL mod_add(LL x, LL y, LL m){
        return (x += y) < m ? x : x - m;
    }

    inline LL mod_mul(LL x, LL y, LL m){
        LL res = x * y - (LL)((long double)x * y / m + 0.5) * m;
        return res < 0 ? res + m : res;
    }

    inline LL mod_pow(LL x, LL n, LL m){
        LL res = 1 % m;
        for (; n; n >>= 1){
            if (n & 1) res = mod_mul(res, x, m);
            x = mod_mul(x, x, m);
        }
        return res;
    }


    /// O(k logn logn logn), k = number of rounds performed
    inline bool miller_rabin(LL n){
        if (n <= 2 || (n & 1 ^ 1)) return (n == 2);
        if (n < MAXP) return spf[n] == n;

        LL c, d, s = 0, r = n - 1;
        for (; !(r & 1); r >>= 1, s++) {}

        /// each iteration is a round
        for (int i = 0; primes[i] < n && primes[i] < 32; i++){
            c = mod_pow(primes[i], r, n);
            for (int j = 0; j < s; j++){
                d = mod_mul(c, c, n);
                if (d == 1 && c != 1 && c != (n - 1)) return false;
                c = d;
            }
            if (c != 1) return false;
        }
        return true;
    }

    inline void init(){
        int i, j, k, cnt = 0;
        for (i = 2; i < MAXP; i++){
            if (!spf[i]) primes[cnt++] = spf[i] = i;
            for (j = 0, k; (k = i * primes[j]) < MAXP; j++){
                spf[k] = primes[j];
                if(spf[i] == spf[k]) break;
            }
        }
    }

    /// Expected complexity O(n^(1/4))
    LL pollard_rho(LL n){
        while (1){
            LL x = rand() % n, y = x, c = rand() % n, u = 1, v, t = 0;
            LL *px = seq, *py = seq;

            while (1){
                *py++ = y = mod_add(mod_mul(y, y, n), c, n);
                *py++ = y = mod_add(mod_mul(y, y, n), c, n);
                if((x = *px++) == y) break;

                v = u;
                u = mod_mul(u, abs(y - x), n);

                if (!u) return __gcd(v, n);
                if (++t == 32){
                    t = 0;
                    if ((u = __gcd(u, n)) > 1 && u < n) return u;
                }
            }

            if (t && (u = __gcd(u, n)) > 1 && u < n) return u;
        }
    }

    vector <LL> factorize(LL n){
        if (n == 1) return vector <LL>();
        if (miller_rabin(n)) return vector<LL> {n};

        vector <LL> v, w;
        while (n > 1 && n < MAXP){
            v.push_back(spf[n]);
            n /= spf[n];
        }
        if (n >= MAXP) {
            LL x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }

        sort(v.begin(), v.end());
        return v;
    }
}
vector <LL> vec;
vector <pair <LL, int > > factor;
map <pair <int, LL >, bool > dp;
map <pair <int, LL >, bool> vis;
LL phi, sol;
bool F(int pos, LL v){
    if(pos == factor.size()){
        if(v == 1){return true;}
        else{return false;}
    }
    if(vis[make_pair(pos, v)]){return dp[make_pair(pos, v)];}
    int i, j;
    bool s1 = false;
    LL p = factor[pos].first;
    LL denom;
    vis[make_pair(pos, v)] = true;
    for(i = 1; i <= factor[pos].second; i += 2){
        denom = (factor[pos].first - 1) * p;
        if(v % denom == 0){
            s1 |= F(pos + 1, v / denom);
        }
        p *= (factor[pos].first * factor[pos].first);
    }
    bool s2 = F(pos + 1, v);
    return dp[make_pair(pos, v)] = s1 | s2;
}
void input(){
    int i, j, cnt = 1;
    sl(phi);
    phi *= 2;
    vec.clear(), factor.clear();
    vec = rho::factorize(phi);
    for(i = 0; i < vec.size(); i++){
        if(i != 0 && vec[i - 1] != vec[i]){
            factor.pub(make_pair((LL)vec[i - 1], (int)cnt));
            cnt = 1;
        }
        else if(i != 0 && vec[i] == vec[i - 1]){cnt++;}
    }
    factor.pub(make_pair(vec[(int)(vec.size()) - 1], cnt));
}
void bt(int pos, LL v){
    if(pos == factor.size()){return;}
    int i, j;
    bool s1 = false;
    LL p = factor[pos].first, q = factor[pos].first;
    LL denom;
    for(i = 1; i <= factor[pos].second; i += 2){
        denom = (factor[pos].first - 1) * p;
        if(v % denom == 0 && F(pos + 1, v / denom)){
            sol = sol * q;
            bt(pos + 1, v / denom);
            return;
        }
        p *= (factor[pos].first * factor[pos].first);
        q *= (factor[pos].first);
    }
    bt(pos + 1, v);
}
void solve(){
    int i, j;
    vis.clear(), dp.clear();
    bool ret = F(0, phi);
    if(!ret){pi(-1);NL; return;}
    sol = 1LL;
    bt(0, phi);
    pl(sol);NL;
}
int main(){
//    freopen("input.txt","r",stdin);
    int cs, ts;
    rho::init();
    si(ts);
    for0(cs, ts){
        input();
        solve();
    }
}
