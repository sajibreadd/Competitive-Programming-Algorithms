/***************knuth morris pratt**********/
void pre(){
    int i,j,k;
    prefix[0]=0;
    for(k=-1,i=1;i<n;i++){
        while(k>=0&&str2[k+1]!=str2[i]){k=prefix[k]-1;}
        if(str2[k+1]==str2[i]){k++;}
        prefix[i]=k+1;
    }
//    para(n,prefix);
}
void solve(int cs){
    int i,j,k;
    for(k=-1,i=0;i<n;i++){
        while(k>=0&&str2[k+1]!=str1[i]){k=prefix[k]-1;}
        if(str2[k+1]==str1[i]){k++;}
        if(i==n-1){break;}
        if(k+1==n){k=prefix[k]-1;}
    }
//    NL;
    int ans=n+n-k-1;
    printf("Case %d: %d\n",cs+1,ans);
}
