/*****linear diophanite equation*******/
/*input:
2 3 5*/
/*output:
-5 5*/
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define SZ 100010
using namespace std;
//ax + by = c
int aa, bb, cc;
int extended_gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = extended_gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
//here x0 and y0 is the solution for equation and c%gcd(a, b) will be 0 otherwise no solution
bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = extended_gcd(abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}
void input(){
    int x0, y0, g;
    bool f = find_any_solution(aa, bb, cc, x0, y0, g);
    printf("%d %d\n", x0, y0);
}
void solve(){
}
int main(){
//    freopen("input.txt","r",stdin);
    while(scanf("%d %d %d", &aa, &bb, &cc) == 3){
        input();
        solve();
    }
}
