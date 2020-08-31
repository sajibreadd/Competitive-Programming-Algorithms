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
#define MOD 7340033
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
#define eps 1e-8
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n | (1<<pos))
#define para(a,b,ara)\
for(int i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    cout<<ara[i];\
}\
printf("\n");
#define pvec(vec)\
for(int i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    cout<<vec[i];\
}\
printf("\n");
#define ppara(n,m,ara)\
for(int i=0;i<n;i++){\
    for(int j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        cout<<ara[i][j];\
    }\
    printf("\n");\
}
#define ppstructara(n,m,ara)\
for(int i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(int j=0;j<m;j++){\
        cout<<ara[i][j];printf("\n")\
    }\
}
#define ppvec(n,vec)\
for(int i=0;i<n;i++){\
    printf("%d:",i);\
    for(int j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        cout<<vec[i][j];\
    }\
    printf("\n");\
}
#define ppstructvec(n,vec)\
for(int i=0;i<n;i++){\
    printf("%d:",i);\
    for(int j=0;j<vec[i].size();j++){\
        cout<<vec[i][j];printf("\n");\
    }\
}
#define sara(a,b,ara)\
for(int i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}
#define pstructara(a,b,ara)\
for(int i=a;i<=b;i++){\
    cout<<ara[i];NL;\
}
#define pstructvec(vec)\
for(int i=0;i<vec.size();i++){\
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
#define ppairvec(vec)\
for(int i=0;i<vec.size();i++){\
    cout<<vec[i].first;SP;cout<<vec[i].second;printf("\n");\
}
#define ppairara(a,b,ara)\
for(int i=a;i<=b;i++){\
    cout<<ara[i].first;SP;cout<<ara[i].second;printf("\n");\
}
#define pppairvec(n,vec)\
for(int i=0;i<n;i++){\
    printf("%d:",i);\
    for(int j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;SP;cout<<vec[i][j].second;NL;\
    }\
}
#define pppairara(n,m,ara)\
for(int i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(int j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;NL;\
    }\
}
//std::ostream & dump(std::ostream &os)const{
//    return os<<"l="<<l
//             <<"r="<<r
//             <<"m="<<m;
//}
//std::ostream & operator<<(ostream &os,seg &s){
//    return s.dump(os);
//}
using namespace std;
//bool status[1010];
//vector <int> prime;
//void siv(){
//	int N=1005,i,j;prime.clear();
//	int sq=sqrt(N);
//	for(i=4;i<=N;i+=2){status[i]=1};
//	for(i=3;i<=sq;i+=2){
//		if(status[i]==0){
//			for(j=i*i;j<=N;j+=i){status[j]=1;}
//		}
//	}
//	status[1]=1;
//    for1(i,N){
//        if(!status[i]){prime.pub(i);}
//    }
//}
int n;
int add(int a,int b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    return ((LL)((LL)(a%MOD)+(LL)(b%MOD)))%MOD;
}
int mul(int a,int b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    return ((LL)((LL)(a%MOD)*(LL)(b%MOD)))%MOD;
}
set <pair<int,int> > mySet;
vector <pair<int,int> > points;
map <pair<int,int >,int> mp;
int frq[2][2][100010];
vector <int> node[2][2];
int to[2][2],inv[100010];
vector <int> sol,choice[2][2];
///Number Theoretic Transformation
const int mod = 7340033;
const int root = 71;                /// set it equal to get_root
const int root_1 = 413523;          /// set it to ip(root, mod - 2)
const int root_pw = 1<<20;          /// mod = c * 2^k + 1 => root_pw = 2^k
vector <int> poly1,poly2;
int gcdExtended(int a,int b,int *x,int *y){
    if(a==0){
        *x=0,*y=1;
        return b;
    }
    int x1,y1;
    int gcd=gcdExtended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
int modInverse(int a,int b){
    int x,y;
    int g=gcdExtended(a,b,&x,&y);
        // m is added to handle negative x
    int res=(x%MOD+MOD)%MOD;
    return res;
}
LL ip(LL a, LL p){
    if(!p) return 1;
    if(p & 1) return ( a * ip(a, p - 1)) % mod;
    LL ret = ip(a, p/2);
    return (ret * ret) % mod;
}
int get_root(){
    int r, q;
    for(r = 2; r < mod; r++){
        if(ip(r, root_pw) == 1){
            for(q = 1; q < root_pw; q++)
                if(ip(r, q) == 1) break;

            if(q == root_pw) return r;
        }
    }
    return -1;
}
void fft (vector<int> & a, bool invert) {
	int sz = (int) a.size();

	for (int i=1, j=0; i<sz; ++i) {
		int bit = sz >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=sz; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<sz; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = ip(sz, mod - 2);
		for (int i=0; i<sz; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<int> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t sz = 1;
	while (sz < max (a.size(), b.size()))  sz <<= 1;
	sz <<= 1;
	fa.resize (sz),  fb.resize (sz);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<sz; ++i)
		fa[i] = ((LL) fa[i] * fb[i]) % mod;
	fft (fa, true);

	res.resize (sz);
	for (size_t i=0; i<sz; ++i)
		res[i] = fa[i];
}
void input(){
    int i,j,u,v,vl,k;
    pair <int,int> tmp;
    bool fx,fy;
    si(n);
    mp.clear();
    points.clear();
    mySet.clear();
    for0(i,n){
        sii(u,v);
        mySet.insert(make_pair(u,v));
        mp[make_pair(u,v)]++;
    }
    points.assign(mySet.begin(),mySet.end());
//    ppairvec(points);NL;
    for0(i,2){
        for0(j,2){node[i][j].clear();}
    }
    mem(frq,0);
    mem(to,0);
    for0(i,points.size()){
        tmp=points[i];
        if(tmp.first>0){fx=false;}
        else{fx=true;}
        if(tmp.second>0){fy=false;}
        else{fy=true;}
//        pii(fx,fy);NL;
        vl=mp[tmp];
//        pi(vl);NL;
        if(frq[fx][fy][vl]==0){
//            piii(fx,fy,vl);NL;
            node[fx][fy].pub(vl);
        }
        frq[fx][fy][vl]++;
        to[fx][fy]+=vl;
    }
    for0(i,2){
        for0(j,2){
            sort(node[i][j].begin(),node[i][j].end());
        }
    }
//    for0(i,2){
//        for0(j,2){
////            printf("to=%d\n",to[i][j]);
//            for0(k,node[i][j].size()){
//                pi(node[i][j][k]);SP;
//            }
//            NL;
//        }
//    }
}
void pre(){
    int i,j;
    for1(i,100000){inv[i]=modInverse(i,MOD);}
}
void solve(){
    int i,j,upor=1,nich=1,k,tmp;
    for0(i,2){
        for0(j,2){
            choice[i][j].clear();
        }
    }
    for0(i,2){
        for0(j,2){
            upor=1;
            nich=1;
            for0(k,to[i][j]+1){
                tmp=mul(upor,nich);
                choice[i][j].pub(tmp);
                upor=mul(upor,to[i][j]-k);
                nich=mul(nich,inv[k+1]);
            }
        }
    }
//    for0(i,2){
//        for0(j,2){
//            for0(k,choice[i][j].size()){
//                pi(choice[i][j][k]);SP;
//            }
//            NL;
//        }
//    }
    poly1.resize(2*min(choice[0][0].size(),choice[1][1].size()));
    for(i=0;i<choice[0][0].size()&&i<choice[1][1].size();i++){
        poly1[2*i]=mul(choice[0][0][i],choice[1][1][i]);
    }
    poly2.resize(2*min(choice[0][1].size(),choice[1][0].size()));
    for(i=0;i<choice[0][1].size()&&i<choice[1][0].size();i++){
        poly2[2*i]=mul(choice[0][1][i],choice[1][0][i]);
    }
    sol.clear();
    multiply(poly1,poly2,sol);
    sol.resize(n+1);
    for(i=1;i<=n;i++){
        if(i!=1){SP;}
        pi(sol[i]);
    }
    NL;
}
int main(){
//    freopen("input.txt","r",stdin);
    int cs,ts;
    pre();
    si(ts);
    for0(cs,ts){
        input();
        printf("Case %d:\n",cs+1);
        solve();
    }
}
