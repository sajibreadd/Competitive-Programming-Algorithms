/***********centroid decomposition************/
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
#define MOD 2
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
#define eps 1e-8
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n  (1<<pos))
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
LL sod[1500010];
struct trp{
    LL u,even,odd,dif;
    trp(){}
    trp(LL _u,LL _even,LL _odd,LL _dif){
        u=_u;even=_even;odd=_odd;dif=_dif;
    }
    bool operator<(const trp &o) const{
        if(dif==o.dif){
            if(odd==o.odd){
                return even<o.even;
            }
            return odd<o.odd;
        }
        return dif<o.dif;
    }
};
vector <trp> carrier[3*100010];
vector <LL> ano[3*100010];
LL ara[3*100010];
vector <trp> vec;
vector <LL> cum;
LL mul(LL _a,LL _b){
    _a=(_a+MOD)%MOD;
    _b=(_b+MOD)%MOD;
    return (_a*_b)%MOD;
}
LL add(LL _a,LL _b){
    _a=(_a+MOD)%MOD;
    _b=(_b+MOD)%MOD;
    return (_a+_b)%MOD;
}
void siv(){
    LL i,j;
    for(i=1;i<=1500001;i++){
        for(j=i;j<=1500001;j+=i){
            sod[j]=add(sod[j],i);
        }
    }
}
/*******************centroid decompose start**********/
long long parent[3*100010],sbtr[3*100010],centroid,n;//here n is the number of vertex
bool markCen[3*100010];
vector <long long> adj[3*100010],adjCen[3*100010];

long long dfs0(long long source,long long par){
    long long i,j;sbtr[source]=1;
    parent[source]=par;
    long long u,s;
    for0(i,adj[source].size()){
        u=adj[source][i];
        if(u!=par){
            sbtr[source]+=dfs0(u,source);
        }
    }
    return sbtr[source];
}
long long getCentroid(long long source,long long par){
    long long i,j,u,mx=-1;
    bool isCen=true;
    long long hvyChld;
    for(i=0;i<adj[source].size();i++){
        u=adj[source][i];
        if(u!=par){
            if(sbtr[u]>n/2){isCen=false;}
            if(sbtr[u]>mx){
                mx=sbtr[u];
                hvyChld=u;
            }
        }
    }
    if(isCen&&n-sbtr[source]<=n/2){return source;}
    return getCentroid(hvyChld,source);
}
void getCentroid(long long connector,long long root,long long source,long long par){
    long long i,j,u,mx=-1,hvyChld;
    bool isCen=true;
    if(source==centroid){
        for(i=0;i<adj[source].size();i++){
            u=adj[source][i];
            if(!markCen[u]&&u!=par){
                getCentroid(source,u,u,source);
            }
        }
    }
    else{
        for(i=0;i<adj[source].size();i++){
            u=adj[source][i];
            if(u!=par&&!markCen[u]){
                if(sbtr[u]>sbtr[root]/2){isCen=false;}
                if(sbtr[u]>mx){
                    mx=sbtr[u];
                    hvyChld=u;
                }
            }
        }
        if(mx==-1){
            adjCen[connector].pub(source);
            adjCen[source].pub(connector);
            markCen[source]=true;
            int p=parent[source];
            while(!markCen[p]){
                sbtr[p]-=sbtr[source];
                p=parent[p];
            }
        }
        else if(isCen&&sbtr[root]-sbtr[source]<=sbtr[root]/2){
            adjCen[connector].pub(source);
            adjCen[source].pub(connector);
            markCen[source]=true;
            int p=parent[source];
            while(!markCen[p]){
                sbtr[p]-=sbtr[source];
                p=parent[p];
            }
            for(i=0;i<adj[source].size();i++){
                u=adj[source][i];
                if(u!=par&&!markCen[u]){
                    getCentroid(source,u,u,source);
                }
            }
            if(!markCen[root]){
                getCentroid(source,root,root,parent[root]);
            }
        }
        else{
            getCentroid(connector,root,hvyChld,source);
        }
    }
}
void decompose(){
    long long i,j,s=dfs0(0,-1);//0 vrtx is root
    centroid=getCentroid(0,-1);
    s=dfs0(centroid,-1);//making centroid as root
    for0(i,n+2){markCen[i]=false;adjCen[i].clear();}
    markCen[centroid]=true;//making centroid as visited
    getCentroid(centroid,centroid,centroid,-1);
//    ppvec(n,adjCen);
}
/*************decompose complete**********************/
void dfs2(LL src,LL root,LL par,LL even,LL odd,bool tick){
    LL i,j,sz=adjCen[src].size(),cnt=0;
    if(tick){
        carrier[root].pub(trp(src,even,odd,odd-even));
        vec.pub(trp(src,even,odd,odd-even));
    }
    if(root==centroid){cnt=0;}
    else{cnt=1;}
    for0(i,adj[src].size()){
        LL u=adj[src][i];
        if(!tick){
            if(u!=par&&!markCen[u]){
                if(ara[u]%2==0){dfs2(u,adjCen[src][cnt],src,even+1,odd,true);}
                else{dfs2(u,adjCen[src][cnt],src,even,odd+1,true);}
                cnt++;
            }
            else if(u==par&&!markCen[u]){
                if(ara[u]%2==0){dfs2(u,adjCen[src][sz-1],src,even+1,odd,true);}
                else{dfs2(u,adjCen[src][sz-1],src,even,odd+1,true);}
            }
        }
        else{
            if(u!=par&&!markCen[u]){
                if(ara[u]%2==0){dfs2(u,root,src,even+1,odd,true);}
                else{dfs2(u,root,src,even,odd+1,true);}
            }
        }
    }
}
bool cmp0(trp lhs,trp rhs){
    if(lhs.dif==rhs.dif){
        if(lhs.odd==rhs.odd){return lhs.even<rhs.even;}
        return lhs.odd<rhs.odd;
    }
    return lhs.dif<rhs.dif;
}
LL dfs1(LL src,LL par){
    LL i,j,u,idx,k;
    std::vector<trp>::iterator it;
    LL sm=0;
    markCen[src]=true;
    vec.clear();
    if(ara[src]%2==0){dfs2(src,src,parent[src],1,0,false);}
    else{dfs2(src,src,parent[src],0,1,false);}
    sort(vec.begin(),vec.end(),cmp0);
    cum.clear();
    cum.resize((size_t)vec.size());
    for0(i,vec.size()){
        if(i==0){cum[i]=vec[i].even+vec[i].odd;}
        else{cum[i]=cum[i-1]+vec[i].even+vec[i].odd;}
    }
    for0(i,vec.size()){
        if(vec[i].dif>=0){sm+=(vec[i].even+vec[i].odd);}
        if(i==0){continue;}
        if(vec[i].dif<0){continue;}
        if(ara[src]%2==0){
            it=lower_bound(vec.begin(),vec.end(),trp(-1,-1,-1,-1*vec[i].dif-1));
        }
        else{
            it=lower_bound(vec.begin(),vec.end(),trp(-1,-1,-1,-1*vec[i].dif+1));
        }
        idx=it-vec.begin();
        if(idx<=i-1){
            if(idx==0){sm+=(cum[i-1]+i*(vec[i].even+vec[i].odd-1LL));}
            else{sm+=(cum[i-1]-cum[idx-1]+(i-idx)*(vec[i].even+vec[i].odd-1LL));}
        }
    }
    for0(i,adjCen[src].size()){
        u=adjCen[src][i];
        if(u!=par&&!markCen[u]){
            sort(carrier[u].begin(),carrier[u].end(),cmp0);
            ano[u].resize((size_t)carrier[u].size());
            for0(j,carrier[u].size()){
                if(j==0){ano[u][j]=carrier[u][j].even+carrier[u][j].odd;}
                else{ano[u][j]=ano[u][j-1]+carrier[u][j].even+carrier[u][j].odd;}
            }
            for0(j,carrier[u].size()){
                if(j==0){continue;}
                if(carrier[u][j].dif<0){continue;}
                if(ara[src]%2==0){
                    it=lower_bound(carrier[u].begin(),carrier[u].end(),trp(-1,-1,-1,-1*carrier[u][j].dif-1));
                }
                else{
                    it=lower_bound(carrier[u].begin(),carrier[u].end(),trp(-1,-1,-1,-1*carrier[u][j].dif+1));
                }
                idx=it-carrier[u].begin();
                if(idx<=j-1){
                    if(idx==0){sm-=(ano[u][j-1]+j*(carrier[u][j].even+carrier[u][j].odd-1LL));}
                    else{sm-=(ano[u][j-1]-ano[u][idx-1]+(j-idx)*(carrier[u][j].even+carrier[u][j].odd-1LL));}
                }
            }
            carrier[u].clear();
            ano[u].clear();
        }
    }
    for0(i,adjCen[src].size()){
        u=adjCen[src][i];
        if(u!=par&&!markCen[u]){
            sm+=dfs1(u,src);
        }
    }
    if(ara[src]%2==1){sm++;}
    return sm;
}
void input(){
    LL i,j;
    sl(n);
    for0(i,n+2){adj[i].clear();carrier[i].clear();}
    for0(i,n-1){
        LL u,v;
        sll(u,v);
        u--;v--;
        adj[u].pub(v);
        adj[v].pub(u);
    }
    for0(i,n){
        sl(ara[i]);ara[i]=sod[ara[i]];
    }
//    para(0,n-1,ara);
}
void solve(){
    LL i,j;
    decompose();
    for0(i,n+2){markCen[i]=false;}
    LL res=dfs1(centroid,-1);
    pl(res);NL;
}
int main(){
    freopen("input.txt","r",stdin);
    siv();
    input();
    solve();
    return 0;
}
