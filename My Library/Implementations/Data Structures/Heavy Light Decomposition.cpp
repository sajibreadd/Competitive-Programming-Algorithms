/***
    * Code of Lightoj-1348 : Aladdin and the Return Journey
    * 1 based arrays and node indexing
    * construct ed
    * ara[nd] contains value on node nd
    * call HLDConstruct()
    * number of nodes n is global
    * Clear ed after the testcase
    * Per Query complexity O(n logn logn)
***/


int n;
int head[MAX];
int it , base[MAX] , pos[MAX] ;
int sub[MAX];
int ara[MAX];
vector <int> ed[MAX];

int L[MAX], P[MAX];

void dfs(int s,int par,int lev) {
    P[s] = par, L[s] = lev, sub[s] = 0;
    int sum = 1;
    for(auto &x : ed[s]) {
        if( x == par ) continue;
        dfs(x,s,lev+1);
        sum += sub[x];
        if(sub[x] > sub[ed[s][0]]  ) swap(x,ed[s][0]);
    }
    sub[s] = sum;
}

struct node{
    int sum;
} tree[4*MAX];

node Merge(node a,node b){
    node ret;
    ret.sum = a.sum + b.sum;
    return ret;
}

void build(int n,int st,int ed){
    if(st==ed){ tree[n].sum = base[st]; return; }
    int mid = (st+ed)/2;
    build(2*n,st,mid);
    build(2*n+1,mid+1,ed);
    tree[n] = Merge(tree[2*n],tree[2*n+1]);
}

void update(int n,int st,int ed,int id,int v){
    if(id>ed || id<st) return;
    if(st==ed && ed==id){ tree[n].sum = base[st] = v; return; }
    int mid = (st+ed)/2;
    update(2*n,st,mid,id,v);
    update(2*n+1,mid+1,ed,id,v);
    tree[n] = Merge(tree[2*n],tree[2*n+1]);
}

node query(int n,int st,int ed,int i,int j){
    if(st>=i && ed<=j) return tree[n];
    int mid = (st+ed)/2;
    if(mid<i) return query(2*n+1,mid+1,ed,i,j);
    else if(mid>=j) return query(2*n,st,mid,i,j);
    else return Merge(query(2*n,st,mid,i,j),query(2*n+1,mid+1,ed,i,j));
}

void HLD( int s , int hd ) {
    pos[s] = ++it;
    base[it] = ara[s];
    head[s] = hd;
    for(auto x : ed[s]) {
        if(x == P[s]) continue;
        HLD( x ,( x == ed[s][0] ? head[s] : x) );
    }
}

void HLDConstruct(){
    it = 0;
    dfs(1,-1,0);
    HLD(1,1);
    build(1,1,n);
}

inline int LCA(int u,int v) {
    while(head[u] != head[v]){
        if(L[head[u]] < L[head[v]]) v = P[head[v]];
        else u = P[head[u]];
    }
    if(L[u]<L[v]) return u;
    else return v;
}

/// path from u to v ( v is an ancestor of u )
int call(int u,int v) {
    int ret = 0,a,b,h;
    while(true){
        a = pos[v];
        if(head[u] != head[v]) h = head[u], a = pos[h];
        b = pos[u];
        ret += query(1,1,n,a,b).sum;
        if(head[u] == head[v]) return ret;
        u = P[h];
    }
}

/// returns the result of the path from node u to node v
int getResult(int u,int v){
    int lca = LCA(u,v);
    return call(u,lca) + call(v,lca) - base[pos[lca]];
}

/// changes the value of node nd to v
void updateNode(int nd, int v){
    nd = pos[nd];
    update(1,1,n,nd,v);
}
