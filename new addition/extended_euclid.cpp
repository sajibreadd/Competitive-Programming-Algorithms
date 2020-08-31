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
#define INF 100000000000000
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
using namespace std;
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
ll gcd(ll a, ll b, ll &x, ll &y){
   if(a == 0){ x = 0, y = 1; return b; }
   ll x1, y1;
   ll d = gcd(b % a, a, x1, y1);
   x = y1 - (b / a) * x1;
   y = x1;
   return d;
}
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
   g = gcd(abs(a), abs(b), x0, y0);
   if(c % g != 0){ return false; }
   x0 *= c / g;
   y0 *= c / g;
   if(a < 0){ x0 *= -1; }
   if(b < 0){ y0 *= -1; }
   return true;
}
ll dv(ll a, ll b, bool f){
   if(((a < 0) ^ (b < 0))){
      if(!f){ return -((abs(a) + abs(b) - 1) / abs(b)); }
      else{ return -(abs(a) / abs(b)); }
   }
   else{
      if(!f){ return abs(a) / abs(b); }
      else{ return (abs(a) + abs(b) - 1) / abs(b); }
   }
}
ll find_all_solution(ll a, ll b, ll c, ll min_x, ll max_x, ll min_y, ll max_y){
   ll x, y, g;
   if(!find_any_solution(a, b, c, x, y, g)){ return -INF; }
   ll kx_min, kx_max, ky_min, ky_max;
   if(b / g >= 0){
      kx_min = dv(min_x - x, b / g, true);
      kx_max = dv(max_x - x, b / g, false);
   }
   else{
      kx_min = dv(max_x - x, b / g, true);
      kx_max = dv(min_x - x, b / g, false);
   }
   if(kx_max < kx_min){ return -INF; }

   if(a / g >= 0){
      ky_min = dv(y - max_y, a / g, true);
      ky_max = dv(y - min_y, a / g, false);
   }
   else{
      ky_min = dv(y - min_y, a / g, true);
      ky_max = dv(y - max_y, a / g, false);
   }
   if(ky_max < ky_min){ return -INF; }

   ll l = max(kx_min, ky_min), r = min(kx_max, ky_max);
   if(l > r){ return -INF; }
   if(b - a >= 0){ return (x + y) + l * (b - a) / g; }
   else{ return (x + y) + r * (b - a) / g; }
}
void solve(){
   ll i, j, n, a, b, t;
   sl(n), sll(a, b), sl(t);
   if(t == 1){
      pl(0ll); nl; return;
   }
   int g = __gcd(a, b);
   if((a / g - 1) * g + b > n - 1){ ps("uh-oh!\n"); return; }
//   for(i = 1; i <= t; i++){
//      if(i + b > n && i - a <= 0){ ps("")}
//   }
   ll ret = find_all_solution(b, -a, t - 1, 0, INF, 0, INF);
   if(ret == -INF){ ps("uh-oh!\n"); }
   else{ pl(ret); nl; }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
   int cs, ts;
   si(ts);
   for0(cs, ts){
      solve();
   }
}
