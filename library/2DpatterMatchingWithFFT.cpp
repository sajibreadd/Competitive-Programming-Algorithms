#include<bits/stdc++.h>
#define pie acos(-1)
#define SZ 1010
using namespace std;
typedef complex<double>base;
char pattern[SZ][SZ], str[SZ][SZ];
vector <int> strVec, patternVec, mulVec;
int resMatrix[SZ][SZ], r, c, n, m;
void input(){
    int i, j;
    for(i = 0; i < r; i++){
        scanf("%s", pattern[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%s", str[i]);
    }
}
void fft(vector<base> &pol, bool invert){
    int i, j, bit, len;
    base u, v;
    int sz = (int)pol.size();
    double ang;
    for(i=1, j=0; i<sz; i++){
        bit = sz >> 1;
        for(; j >= bit; bit >>= 1){
            j -= bit;
        }
        j += bit;
        if(i < j){swap(pol[i], pol[j]);}
    }
    for(len = 2; len <= sz; len <<= 1){
        ang = 2*pie/len*(invert?-1:1);
        base wlen(cos(ang), sin(ang));
        for(i=0; i < sz; i += len){
            base w(1);
            for(j = 0; j < len/2; j++){
                u = pol[i + j];
                v = pol[i + j+ len/2]*w;
                pol[i + j]=u + v;
                pol[i + j+ len/2]=u - v;
                w *= wlen;
            }
        }
    }
    if(invert){
        for(i=0; i < sz; i++){
            pol[i] /= (int)sz;
        }
    }
}
void polMul(const vector <int> &pol1, const vector <int> &pol2, vector <int> &ret){
    int i, j;
    vector <base> fa(pol1.begin(),pol1.end());
    vector <base> fb (pol2.begin(),pol2.end());
    size_t sz = 1;
    while(sz < max(pol1.size(), pol2.size())){sz <<= 1;}
    sz <<= 1;
    fa.resize(sz); fb.resize(sz);
    fft(fa,false), fft(fb,false);
    for(size_t i = 0; i < sz; i++){
        fa[i] *= fb[i];
    }
    fft(fa, true);
    ret.resize(sz);
    for(size_t i = 0; i < sz; i++){
        ret[i] = (int)(fa[i].real() + 0.5);
    }
    fa.clear();
    fb.clear();
}
int matching(){
    int i, j, ch, cnt, k;
    for(i = 0; i < n; i++){
        for(j =0; j < m; j++){
            resMatrix[i][j] = 1;
        }
    }
    for(ch = 'a'; ch <= 'b'; ch++){
        patternVec.clear();
        strVec.clear();
        mulVec.clear();
        cnt = 0;
        for(i = 0; i < n; i++){
            for(j =0; j < m; j++){
                if(i <= r - 1 && j <= c - 1){
                    if(pattern[i][j] == ch){
                        patternVec.push_back(1); cnt++;
                    }
                    else{patternVec.push_back(0);}
                }
                else{patternVec.push_back(0);}
                if(str[i][j] == ch){strVec.push_back(1);}
                else{strVec.push_back(0);}
            }
        }
        reverse(patternVec.begin(), patternVec.end());
        polMul(strVec, patternVec, mulVec);
        for(i = 0; i <= n - r; i++){
            for(j = 0; j <= m - c; j++){
                if(i*m + j + m*n - 1 < (int)mulVec.size()){
                    resMatrix[i][j] &= (mulVec[i*m + j + m*n - 1] == cnt);
                }
                else{
                    resMatrix[i][j] &= 0;
                }
            }
        }
    }
    for(i = 0, cnt = 0; i <= n - r; i++){
        for(j = 0; j <= m - c; j++){
            cnt += resMatrix[i][j];
        }
    }
    return cnt;
}
void solve(){
}
int main(){
    freopen("input.txt","r",stdin);
    int ret;
    while(scanf("%d %d %d %d", &r, &c, &n, &m) == 4){
        input();
        ret = matching();
        printf("%d\n", ret);
    }
}
