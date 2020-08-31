/**************matrix Exponetiation**********************/
void matMul(unsigned _a[][55],unsigned _b[][55]){
    int i,j,k;
    unsigned _c[55][55];
    for0(i,len+1){
        for0(j,len+1){
            _c[i][j]=0;
            for0(k,len+1){
                _c[i][j]+=(_a[i][k]*_b[k][j]);
            }
        }
    }
    for0(i,len+1){
        for0(j,len+1){
            _a[i][j]=_c[i][j];
        }
    }
}
void matExpo(){
    int i,j;
    for0(i,len+1){
        for0(j,len+1){
            if(i==j){resMat[i][j]=1;}
            else{resMat[i][j]=0;}
            zMat[i][j]=mat[i][j];
        }
    }
    i=n;
    while(i!=0){
        if(i%2==1){matMul(resMat,zMat);}
        matMul(zMat,zMat);i/=2;
    }
}
