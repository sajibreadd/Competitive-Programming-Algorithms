const int N = 75; 
namespace wm{
	bool vis[N + 5]; 
	int U[N + 5], V[N + 5], P[N + 5], way[N + 5], minv[N + 5], match[N + 5], ar[N + 5][N + 5]; 
	int hungarian(int n, int m, int mat[N + 5][N + 5], int flag){
		mem(U, 0), mem(V, 0), mem(P, 0), mem(ar, 0), mem(way, 0); 
		int i, j; 
		for1(i, n){
			for1(j, m){
				ar[i][j] = mat[i][j]; 
				if(flag == +1) ar[i][j] = -ar[i][j]; 
			}
		}
		if(n > m) m = n; 
		int a, b, c, d, r, w; 
		for1(i, n){
			P[0] = i, b = 0; 
			for0(j, m + 1) minv[j] = INF, vis[j] = 0; 
			do{
				vis[b] = 1; 
				a = P[b], d = 0, w = INF; 
				for1(j, m){
					if(!vis[j]){
						r = ar[a][j] - U[a] - V[j]; 
						if(r < minv[j]) minv[j] = r, way[j] = b; 
						if(minv[j] < w) w = minv[j], d = j; 
					}
				}
				for0(j, m + 1){
					if(vis[j]) U[P[j]] += w, V[j] -= w; 
					else minv[j] -= w; 
				}
				b = d; 
			} while(P[b] != 0); 
			do{
				d = way[b]; 
				P[b] = P[d], b = d; 
			} while(b != 0); 
		}
		for1(j, m) match[j] = P[j]; 
		return (flag == +1) ? V[0] : -V[0]; 
	}
}
void solve(){
}
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
}