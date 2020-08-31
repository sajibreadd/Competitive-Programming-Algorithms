/***********heavy light decomposition**********/
/*input:
9
1 2
1 3
2 4
2 8
3 7
3 9
4 6
4 5*/
/*output:
vrtx = 0 hldNo = 0 hldHead = 0 hldpos = 0 chainLink = -1 hldSz = 4
vrtx = 1 hldNo = 0 hldHead = 0 hldpos = 1 chainLink = -1 hldSz = 4
vrtx = 3 hldNo = 0 hldHead = 0 hldpos = 2 chainLink = -1 hldSz = 4
vrtx = 5 hldNo = 0 hldHead = 0 hldpos = 3 chainLink = -1 hldSz = 4
vrtx = 4 hldNo = 1 hldHead = 4 hldpos = 4 chainLink = 3 hldSz = 1
vrtx = 7 hldNo = 2 hldHead = 7 hldpos = 5 chainLink = 1 hldSz = 1
vrtx = 2 hldNo = 3 hldHead = 2 hldpos = 6 chainLink = 0 hldSz = 2
vrtx = 6 hldNo = 3 hldHead = 2 hldpos = 7 chainLink = 0 hldSz = 2
vrtx = 8 hldNo = 4 hldHead = 8 hldpos = 8 chainLink = 2 hldSz = 1*/
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <vector>
#define SZ 100010
using namespace std;
//0 based index
//makeHld() should be called just
int n;//number of vertex
vector <int> adj[SZ];//adjacency list should be cleared first
/**hld starts here***/
int hldNo[SZ], hldHead[SZ], hldSz[SZ], hldPos[SZ], chainLink[SZ];
int sbtr[SZ], hldCnt = 0, nodeCnt = 0;
//here hldNo array's index will be vrtx id
//here hldHead's index will be hldNo
//here hldSz's index will be hldNo
//here hldPos is position of vrtx in the segment tree
//chainLink's index will be hldNo
/*depedency graph of these array is given below:
hldHead---->hldNo-->vrtxId
hldSz------>hldNo-->vrtxId
chainLink-->hldNo-->vrtxId*/
vector <int> vrtx;
int dfs(int src, int par){
    int i, j, u;
    sbtr[src] = 1;
    for(i = 0; i < adj[src].size(); i++){
        u = adj[src][i];
        if(u != par){
            sbtr[src] += dfs(u, src);
        }
    }
    return sbtr[src];
}
void bldHld(int src, int par, bool f){
    int i, j, bigChild = -1, mx = -1, u;
    vrtx.push_back(src);
    if(f){
        hldCnt++;
        hldHead[hldCnt - 1] = src;
        hldSz[hldCnt - 1] = 0;
        chainLink[hldCnt - 1] = par;
    }
    hldNo[src] = hldCnt - 1;
    hldPos[src] = nodeCnt++;
    hldSz[hldCnt - 1]++;
    for(i = 0; i < adj[src].size(); i++){
        u = adj[src][i];
        if(u != par){
            if(sbtr[u] > mx){
                mx = sbtr[u];
                bigChild = u;
            }
        }
    }
    if(bigChild != -1){
        bldHld(bigChild, src, false);
    }
    for(i =0; i < adj[src].size(); i++){
        u = adj[src][i];
        if(u != par && u != bigChild){
            bldHld(u, src, true);
        }
    }
}
void makeHld(){
    int i, j, s = dfs(0, -1);//here 0 is root
    hldCnt = 0; nodeCnt = 0; vrtx.clear();
    bldHld(0, -1, true);
    //to debug this portion should be comment in
//    for(i = 0; i < vrtx.size(); i++){
//        printf("vrtx = %d hldNo = %d hldHead = %d hldpos = %d chainLink = %d hldSz = %d\n",
//               vrtx[i], hldNo[vrtx[i]], hldHead[hldNo[vrtx[i]]], hldPos[vrtx[i]], chainLink[hldNo[vrtx[i]]],
//               hldSz[hldNo[vrtx[i]]]);
//    }
}
//void update(int u, int v){//here v is ancestor of u querying from u to ancestor v
//    int i, j, s = u, e;
//    global = false;
//    while(1){
//        if(hldHead[hldNo[s]] == hldHead[hldNo[v]]){
//            e = v;
//            update(0, n - 1, 0, hldPos[e], hldPos[s], ht[u]);
//            break;
//        }
//        e = hldHead[hldNo[s]];
//        update(0, n - 1, 0, hldPos[e], hldPos[s], ht[u]);
//        if(global){break;}
//        s = chainLink[hldNo[s]];
//    }
////    pi(global);NL;
//}
//int query(int u, int v){// here v is ancestor of u querying from u to ancestor v
//    int i, j, s = u, e, ret = INF, ans;
//    while(1){
//        if(hldHead[hldNo[s]] == hldHead[hldNo[v]]){
//            e = v;
//            ans = query(0, n - 1, 0, hldPos[e], hldPos[s]);
//            ret = min(ret, ans);
//            break;
//        }
//        e = hldHead[hldNo[s]];
//        ans = query(0, n - 1, 0, hldPos[e], hldPos[s]);
//        ret = min(ret, ans);
//        s = chainLink[hldNo[s]];
//    }
//    return ht[u] + ret;
//}
void input(){
    int i, j, u, v;
    for(i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeHld();
}
void solve(){
}
int main(){
//    freopen("input.txt","r",stdin);
    while(scanf("%d", &n) == 1){
        input();
        solve();
    }
}
