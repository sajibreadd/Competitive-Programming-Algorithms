#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define INF INT_MAX
#define SZ 100010
using namespace std;
/***********************************************start of dinitsa****************************************/
struct edge{
    int a,b,cap,flow;
    edge(){}
    edge(int _a,int _b,int _cap,int _flow){
        a=_a;b=_b;cap=_cap;flow=_flow;
    }
};
int n;//n is the number of vertex
vector <edge> e;
const int MAXN=110;//MAXN is the maximum number of vertex in the input constrain
vector <int> g[MAXN];
int s,t,ptr[MAXN],q[MAXN],d[MAXN];//s is source and t is sink
int deg[MAXN],mnk;
void add_edge (int a, int b, int cap) {
	edge e1 = edge(a, b, cap, 0);
	edge e2 = edge(b, a, 0, 0);
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d,-1,sizeof(d));
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
int dinitsa() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof(ptr));
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}
void rst(){
    int i, j;
    e.clear();
    for(i = 0; i < n + 2; i++){g[i].clear();}
}
/*****************************************end of dinitsa***************************************************/
void input(){
    rst();//rst should be called before using it
}
void solve(){
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
}
