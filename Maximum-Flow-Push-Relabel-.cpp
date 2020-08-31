#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define nl puts("")
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf %lf",&a,&b)
#define sddd(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sp printf(" ")
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define mpr make_pair
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
    cout<<ara[i];nl;\
}
#define pstructvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i];nl;\
}
#define pstructstl(stl,x)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    x=*it;\
    cout<<x;nl;\
}\
nl;
#define pstl(stl)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    if(it!=stl.begin()){sp;}\
    pi(*it);\
}\
nl;
#define ppairvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i].first;sp;cout<<vec[i].second;printf("\n");\
}
#define ppairara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i].first;sp;cout<<ara[i].second;printf("\n");\
}
#define pppairvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;sp;cout<<vec[i][j].second;nl;\
    }\
}
#define pppairara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;nl;\
    }\
}
#define SZ 2 * 100010
#define xx first
#define yy second
using namespace std;
//using namespace __gnu_pbds;
//bool status[100010];
//vector <int> prime;
//void siv(){
//    int N = 100005, i, j; prime.clear();
//    int sq = sqrt(N);
//    for(i = 4; i <= N; i += 2){ status[i] = true; }
//    for(i = 3; i <= sq; i+= 2){
//        if(status[i] == false){
//            for(j = i * i; j <= N; j += i){ status[j] = true; }
//        }
//    }
//    status[1] = true;
//    for1(i, N){ if(!status[i]){ prime.pub(i); } }
//}
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
//auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
//std::mt19937 mt(seed);
inline int add(int _a, int _b){
    if(_a < 0){ _a += MOD; }
    if(_b < 0){ _b += MOD; }
    if(_a + _b >= MOD){ return _a + _b - MOD; }
    return _a + _b;
}
inline int mul(int _a, int _b){
    if(_a < 0){ _a += MOD; }
    if(_b < 0){ _b += MOD; }
    return ((ll)((ll)_a * (ll)_b)) % MOD;
}
struct edge{
    int dest, back;
    ll f, c;
    edge(int d, int b, ll f, ll c) : dest(d), back(b), f(f), c(c){}
};
struct push_relabel{
    vector < vector < edge > > g;
    vector <ll> ec;
    vector < edge* > cur;
    vector < vector <int > > hs;
    vector < int > H;
    push_relabel (int n) : g(n), ec(n), cur(n), hs(n + n), H(n){}
    void add_edge(int s, int t, ll cap, ll rcap = 0){
        if(s == t) return;
        g[s].emplace_back(t, g[t].size(), 0, cap);
        g[t].emplace_back(s, g[s].size() - 1, 0, rcap);
    }
    void add_flow(edge & e, ll f){
        edge & back = g[e.dest][e.back];
        if(!ec[e.dest] && f) hs[H[e.dest]].emplace_back(e.dest);
        e.f += f, e.c -= f, ec[e.dest] += f;
        back.f -= f, back.c += f, ec[back.dest] -= f;
    }
    ll max_flow(int s, int t){
        int v = g.size(), i, j; H[s] = v, ec[t] = 1;
        vector <int> co(v + v); co[0] = v - 1;
        for0(i, v) cur[i] = g[i].data();
        for(auto & e : g[s]) add_flow(e, e.c);
        for(int hi = 0; ; ){
            while(hs[hi].empty()) if(!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while(ec[u] > 0){
                if(cur[u] == g[u].data() + g[u].size()){
                    H[u] = 1e9 + 5;
                    for(auto & e : g[u]) if(e.c && H[u] > H[e.dest] + 1) H[u] = H[e.dest] + 1, cur[u] = &e;
                    if(++co[H[u]], !--co[hi] && hi < v){
                        for0(i, v) if(hi < H[i] && H[i] < v) --co[H[i]], H[i] = v + 1;
                    }
                    hi = H[u];
                }
                else if(cur[u]->c && H[u] == H[cur[u]->dest] + 1) add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
            }
        }
    }
};
int main(){
//     freopen("input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
}
