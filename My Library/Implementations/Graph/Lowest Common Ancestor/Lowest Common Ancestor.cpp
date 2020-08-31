/// 1 based indexing , n = number of nodes
const int MAX = 100010;

int lg;
int L[MAX]; /// Depth of a node
int P[MAX][20]; /// P[i][j] denotes (2^j)th parent of node i

vector <int> ed[MAX];

void dfs(int s,int par,int lev){
    int i,x;
    L[s] = lev;
    for(i=0; i<ed[s].size(); i++){
        x = ed[s][i];
        if(x!=par){
            P[x][0] = s;
            dfs(x,s,lev+1);
        }
    }
}

void lca_build(int n,int root){
    SET(P);

    dfs(root,-1,0);

    lg = (log(n)/log(2.0))+2;

    int i,j;
    for(j=1; (1<<j)<=n; j++)
        for(i=1; i<=n; i++)
            if(P[i][j-1]!=-1) P[i][j] = P[P[i][j-1]][j-1];
}

inline int lca_query(int x,int y){
    if(L[x]<L[y]) swap(x,y);
    int i,j;
    for(i=lg; i>=0; i--)
        if(L[x] - (1<<i) >= L[y]) x = P[x][i];

    if(x==y) return x;
    for(i=lg; i>=0; i--) {
        if(P[x][i]!=-1 && P[x][i]!=P[y][i]) {
            x = P[x][i];
            y = P[y][i];
        }
    }
    return P[x][0];
}
