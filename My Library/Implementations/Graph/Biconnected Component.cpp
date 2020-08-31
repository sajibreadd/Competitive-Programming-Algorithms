// clear ed[] every test case
// tot -> total number of components
// bcc[i] contains the nodes of the i'th component

const int MAX = ?;
vector <int> ed[MAX];
bool isArt[MAX];
int tot, Time, low[MAX], st[MAX];
vector <int> bcc[MAX];
stack <int> S;

void popBCC(int s,int x) {
    isArt[s] = 1;
    bcc[++tot].pb(s);
    while(bcc[tot].back() ^ x) {
        bcc[tot].pb(S.top());
        S.pop();
    }
}

void dfs(int s, int p = -1) {
    S.push(s);
    int ch = 0;
    st[s] = low[s] = ++Time;
    for(int x : ed[s]) {
        if(!st[x]) {
            ch++;
            dfs(x,s);
            low[s] = min(low[s],low[x]);
            if(p != -1 && low[x] >= st[s]) popBCC(s,x);
            else if(p == -1) if(ch > 1) popBCC(s,x);
        }
        else if(p != x) low[s] = min(low[s],st[x]);
    }
    if(p == -1 && ch > 1) isArt[s] = 1;
}


void processBCC(int n) {
    for(int i=1;i<=n;i++) bcc[i].clear();
    CLR(st); CLR(isArt);
    Time = tot = 0;
    for(int i=1; i<=n; i++) {
        if(!st[i]) {
            dfs(i,-1);
            if(!S.empty()) ++tot;
            while(!S.empty()) {
                bcc[tot].push_back(S.top());
                S.pop();
            }
        }
    }
}
