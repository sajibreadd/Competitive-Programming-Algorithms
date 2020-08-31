/*input:
3 3 3
1 1 1
2 1 2
3 2 3
output:
4*/
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define INF 1000//this should be initialized by (edge sum + 1)
#define MAX 1010
#define SZ 100010
#define MAXIMIZE +1
#define MINIMIZE -1
using namespace std;
namespace wm{ /// hash = 581023
    bool visited[MAX];
    int U[MAX], V[MAX], P[MAX], way[MAX], minv[MAX], match[MAX], ar[MAX][MAX], ret;

    /// n = number of row and m = number of columns in 1 based, flag = MAXIMIZE or MINIMIZE
    /// match[i] contains the column to which row i is matched
    int hungarian(int n, int m, int mat[MAX][MAX], int flag){
        memset(U, 0, sizeof(U)), memset(V, 0, sizeof(V)), memset(P, 0, sizeof(P)), memset(ar, 0, sizeof(ar)), memset(way, 0, sizeof(way));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                ar[i][j] = mat[i][j];
                if (flag == MAXIMIZE) ar[i][j] = -ar[i][j];
            }
        }
        if (n > m) m = n;

        int i, j, a, b, c, d, r, w;
        for (i = 1; i <= n; i++){
            P[0] = i, b = 0;
            for (j = 0; j <= m; j++) minv[j] = INF, visited[j] = false;

            do{
                visited[b] = true;
                a = P[b], d = 0, w = INF;

                for (j = 1; j <= m; j++){
                    if (!visited[j]){
                        r = ar[a][j] - U[a] - V[j];
                        if (r < minv[j]) minv[j] = r, way[j] = b;
                        if (minv[j] < w) w = minv[j], d = j;
                    }
                }

                for (j = 0; j <= m; j++){
                    if (visited[j]) U[P[j]] += w, V[j] -= w;
                    else minv[j] -= w;
                }
                b = d;
            } while (P[b] != 0);

            do{
                d = way[b];
                P[b] = P[d], b = d;
            } while (b != 0);
        }
        for (j = 1; j <= m; j++) match[P[j]] = j;

        ret = (flag == MINIMIZE) ? -V[0] : V[0];
        if(flag == MINIMIZE){
            while(ret >= INF){
                ret -= INF;
            }
        }
        return ret;
    }
}
int n, m, adj[1010][1010], k;
void input(){
    int i, j, u, v, w;
    scanf("%d %d %d",&n, &m, &k);//here k is the number of edge
    for(i = 0; i < max(n, m) + 1; i++){
        for(j = 0; j < max(n, m) + 1; j++){
            adj[i][j] = INF;
            //adj[i][j] = INF for minimization
            //adj[i][j] = 0 for maximization
        }
    }
    for(i = 0; i < k; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
void solve(){
    int cost = wm::hungarian(n, m, adj, MINIMIZE);
    printf("%d\n", cost);
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
}
