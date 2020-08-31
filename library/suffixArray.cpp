/**************************************suffix array***********************************************/
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define SZ 100010
using namespace std;
char str[SZ];
int s0[(SZ / 3) + 10], sa0[(SZ / 3) + 10], n;//n is the length of the string
int  ar[SZ], sa[SZ], lcp[SZ], bucket[SZ], mem[SZ << 2];//ar contains the suffix index of i'th suffix
int LCP[SZ];//LCP is the longest commos prefix of 2 consecutive string in suffix array
void radixsort(int* source, int* dest, int* val, int n, int lim){ /// hash = 349247
    int i, s = 0, x;
    memset(bucket, 0, lim << 2);
    for (i = 0; i < n; i++) bucket[val[source[i]]]++;

    for (i = 0; i < lim; i++){
        x = bucket[i];
        bucket[i] = s, s += x;
    }
    for (i = 0; i < n; i++) dest[bucket[val[source[i]]]++] = source[i];
}
void DC3(int* ar, int* sa, int n, int lim, int ptr){ /// hash = 758459
    int *s12, *sa12;
    int allc = (n / 3) << 1, n0 = (n + 2) / 3;
    int i, j, k, l, c, d, p, t, m, r, counter;
    s12 = &mem[ptr], ptr += (allc + 5), sa12 = &mem[ptr], ptr += (allc + 5);

    c = 0, m = 0, r = n + ((n % 3) == 1);
    for (i = 0; i < r; i++, m++){
        if (m == 3) m = 0;
        if (m) s12[c++] = i;
    }
    s12[c] = sa12[c] = s12[c + 1] = sa12[c + 1] = s12[c + 2] = sa12[c + 2] = 0;
    radixsort(s12, sa12, ar + 2, c, lim + 1);
    radixsort(sa12, s12, ar + 1, c, lim + 1);
    radixsort(s12, sa12, ar, c, lim + 1);

    counter = 0, j = -1;
    for (i = 0; i < c; i++){
        if ((ar[sa12[i]] != j) || (ar[sa12[i] + 1] != k) || (ar[sa12[i] + 2] != l)){
            counter++;
            j = ar[sa12[i]], k = ar[sa12[i] + 1], l = ar[sa12[i] + 2];
        }
        if((sa12[i] % 3) == 1) s12[sa12[i] / 3] = counter;
        else s12[(sa12[i] / 3) + n0] = counter;
    }

    if (counter == c){
        for(i = 0; i < c; i++) sa12[s12[i] - 1] = i;
    }
    else{
        DC3(s12, sa12, c, counter, ptr);
        for (i = 0; i < c; i++) s12[sa12[i]] = i + 1;
    }

    for (i = 0, d = 0; i < c; i++){
        if (sa12[i] < n0) s0[d++] = (sa12[i] * 3);
    }
    radixsort(s0, sa0, ar, d, lim + 1);
    for (k = 0, l = ((n % 3) == 1), r = 0; r < n; r++){
        j = sa0[k];
        i = ((sa12[l] < n0) ? (sa12[l] * 3) + 1 : ((sa12[l] - n0) * 3) + 2);
        if (l == c) sa[r] = sa0[k++];
        else if (k == d) sa[r] = i, l++;
        else{
            if (sa12[l] < n0){
                if ((ar[i] < ar[j]) || (ar[i] == ar[j] && s12[sa12[l] + n0] <= s12[j / 3])) sa[r] = i, l++;
                else sa[r] = j, k++;
            }
            else{
                if ((ar[i] < ar[j]) || (ar[i] == ar[j] && ar[i + 1] < ar[j + 1]) || (ar[i] == ar[j] && ar[i + 1] == ar[j + 1] && s12[sa12[l] - n0 + 1] <= s12[(j /3) + n0]) ) sa[r] = i, l++;
                else sa[r] = j, k++;
            }
        }
    }
}
void Generate(){
    int i, j, lim = 0;
    for (i = 0; i < n; i++){
        ar[i] = str[i];
        if (ar[i] > lim) lim = ar[i];
    }

    ar[n] = ar[n + 1] = ar[n + 2] = 0;
    DC3(ar, sa, n, lim, 0);
}
void LcpArray(){ /// hash = 935019
    int i, j, k,iter;
    for (i = 0; i < n; i++) ar[sa[i]] = i;
    for (k = 0, i = 0; i < n; i++, k?k--:0){
        if (ar[i] == (n - 1)) k = 0;
        else{
            j = sa[ar[i] + 1];
            while(((i + k) < n) && ((j + k) < n) && (str[i + k] == str[j + k])) k++;
        }
        lcp[ar[i]] = k;
    }
    for(i=0,j=1;i<n-1;i++,j++){
        LCP[j]=lcp[ar[sa[i]]];
    }
    LCP[0]=lcp[ar[sa[n-1]]];
}
void input(){
    scanf("%s", str);
}
void solve(){
    int i, j;
    Generate();
    LcpArray();
    for(i = 0; i < n; i++){
        if(i != 0){printf(" ");}
        printf("%d",sa[i]);
    }
    printf("\n");
    for(i = 0; i < n; i++){
        if(i != 0){printf(" ");}
        printf("%d", LCP[i]);
    }
    printf("\n");
}
int main(){
//    freopen("input.txt","r",stdin);
    while(scanf("%d", &n) == 1){
        input();
        solve();
    }
}
