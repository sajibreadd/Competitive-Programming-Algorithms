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
#define SZ 10010
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
int n, W[SZ], ht[SZ], cost[SZ], go[SZ];
int wt[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string word[SZ], str[SZ];
vector <int> compo[SZ];
unordered_map <string, int> mp;
unordered_map <string, int> mp_idx;
set <string> st;
vector <string> all_word;
queue <int> Q;
void input(){
   int i, j;
   si(n);
   for0(i, n){
      cin >> word[i]; str[i] = word[i]; mp_idx[word[i]] = i;
      for0(j, word[i].size()){ W[i] += wt[word[i][j] - 'a']; }
      sort(str[i].begin(), str[i].end());
      st.insert(str[i]);
   }
   all_word.assign(st.begin(), st.end());
   for0(i, all_word.size()){
      mp[all_word[i]] = i;
   }
   for0(i, n){ compo[mp[str[i]]].push_back(i); go[i] = mp[str[i]]; }
}
pair <int, int> bfs(int src, int des){
   int i, j, u, idx, v;
   string tmp;
   for0(i, n){ ht[i] = -1; cost[i] = 0; }
   while(!Q.empty()){ Q.pop(); }
   Q.push(src); ht[src] = 0; cost[src] = W[src];
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      if(u == des){ return mpr(ht[des], cost[des]); }
      idx = go[u];
      for0(i, compo[idx].size()){
         v = compo[idx][i];
         if(u == v){ continue; }
         if(ht[v] == -1){
            ht[v] = ht[u] + 1;
            cost[v] = cost[u] + W[v];
            Q.push(v);
         }
         else if(ht[v] == ht[u] + 1){
            cost[v] = max(cost[v], cost[u] + W[v]);
         }
      }
      for(i = 0, tmp = word[u]; i < word[u].size(); i++){
         for(j = 'a'; j <= 'z'; j++){
            if(j == word[u][i]){ continue; }
            tmp[i] = (char)j;
            if(mp_idx.find(tmp) != mp_idx.end()){
               v = mp_idx[tmp];
               if(ht[v] == -1){
                  ht[v] = ht[u] + 1;
                  cost[v] = cost[u] + W[v];
                  Q.push(v);
               }
               else if(ht[v] == ht[u] + 1){
                  cost[v] = max(cost[v], cost[u] + W[v]);
               }
            }
         }
         tmp[i] = word[u][i];
      }
   }
   return mpr(-1, 0);
}
void solve(){
   int i, j, q, u, v;
   pair <int, int> ret;
   string A, B, ntn;
   si(q);
   for0(i, q){
      cin >> A >> ntn >> B;
      if(A == B){
         cout << A << " " << ntn << " " << B << " " << 0 << " " << 0; nl; continue;
      }
      if(mp_idx.find(B) == mp_idx.end() || mp_idx.find(A) == mp_idx.end()){
         cout << A << " " << ntn << " " << B << " " << "IMPOSSIBLE"; nl; continue;
      }
      u = mp_idx[A], v = mp_idx[B];
      ret = bfs(u, v);
      if(ret.first == -1){
         cout << A << " " << ntn << " " << B << " " << "IMPOSSIBLE"; nl;
      }
      else{
         cout << A << " " << ntn << " " << B << " " << ret.first << " " << ret.second - W[u] - W[v]; nl;
      }
   }
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
   input();
   solve();
}
