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
#define SZ 1000010
using namespace std;
bool status[SZ];
ll prime[SZ], p_cnt = 0;
void siv(){
    ll N = 1000005, i, j;
    ll sq = sqrt(N);
    for(i = 4; i <= N; i += 2){ status[i] = true; }
    for(i = 3; i <= sq; i+= 2){
        if(status[i] == false){
            for(j = i * i; j <= N; j += i){ status[j] = true; }
        }
    }
    status[1] = true;
    for1(i, N){ if(!status[i]){ prime[p_cnt++] = i; } }
}
ll add(ll _a, ll _b){
   _a = (_a + MOD) % MOD;
   _b = (_b + MOD) % MOD;
   return (_a + _b) % MOD;
}
ll mul(ll _a, ll _b){
   _a = (_a + MOD) % MOD;
   _b = (_b + MOD) % MOD;
   return ((ll)((ll)_a * (ll)_b)) % MOD;
}
// all number n, where phi(n) = x;
ll phi;
vector <ll> res;
vector < pair <ll, ll > > factorize(ll x){
   ll i, j;
   vector < pair <ll, ll > > ret;
   for(i = 0; i < p_cnt && prime[i] <= x / prime[i]; i++){
      if(x % prime[i] == 0){
         ret.push_back(mpr(prime[i], 0));
         while(x % prime[i] == 0){ ret.back().second++; x /= prime[i]; }
      }
   }
   if(x != 1){ ret.push_back(mpr(x, 1)); }
   return ret;
}
bool is_prime(ll x){
   ll i, j;
   if(x <= 1000000){ return (!status[x]); }
   for(i = 0; i < p_cnt && prime[i] <= x / prime[i]; i++){
      if(x % prime[i] == 0){ return false; }
   }
   return true;
}
void div_search(ll pos, ll d, ll thresh, vector <pair <ll, ll > > & factor, vector <ll> &divisor){
   if(thresh == 0){ return; }
   ll i, j, ret = d;
   if(pos == factor.size()){ divisor.push_back(d); return; }
   div_search(pos + 1, d, thresh, factor, divisor);
   for(i = 0; i < factor[pos].second; i++){
      if(d <= thresh / factor[pos].first){
         d *= factor[pos].first;
         div_search(pos + 1, d, thresh, factor, divisor);
      }
   }
}
void F(ll x, ll y, ll mx_prime){
   if(x == 1){
      res.push_back(y);
      if(mx_prime > 2){ res.push_back(2ll * y); }
      return;
   }
   ll i, j, d, u, v;
   vector < pair <ll, ll > > factor = factorize(x);
   vector <ll> divisor;
   div_search(0, 1, mx_prime - 2, factor, divisor);
   sort(divisor.begin(), divisor.end());
//   pi(x), ps("-->"); sp; pvec(i, divisor);
   for0(i, divisor.size()){
      d = divisor[i];
      if(is_prime(d + 1)){
         u = x / d, v = y;
         while(u % (d + 1) == 0){ u /= (d + 1), v *= (ll)(d + 1); }
         v *= (ll)(d + 1);
         F(u, v, d + 1);
      }
   }
}
void solve(){
   ll i, j;
   res.clear();
   F(phi, 1ll, INF);
   if(res.size() == 0){ ps("No solution.\n"); return; }
   sort(res.begin(), res.end());
   for0(i, res.size()){
      if(i != 0){ sp; }
      pl(res[i]);
   } nl;
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
   ll i, j;
   siv();
   while(si(phi) == 1){
      solve();
   }
}
