/***
    Finds the largest rectangular area possible in a given histogram where
    the largest rectangle can be made of a number of contiguous bars.
***/


int solve(vector <int> &V) {
    V.push_back(0);
    int n = V.size();
    int ans = 0;
    stack <int> S;
    for(int i=0;i<V.size();i++) {
        int y = V[i];
        while(!S.empty()) {
            int x = V[S.top()];
            if(x >= y) {
                S.pop();
                if(S.empty()) ans = max(ans,i*x);
                else ans = max(ans,(i-S.top()-1)*x);
            }
            else break;
        }
        S.push(i);
    }
    V.pop_back();
    return ans;
}

