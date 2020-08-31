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
                    if(pattern[i][j] == ch){ patternVec.push_back(1); cnt++; }
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
                if(i*m + j + m*n - 1 < (int)mulVec.size()){ resMatrix[i][j] &= (mulVec[i*m + j + m*n - 1] == cnt); }
                else{ resMatrix[i][j] &= 0; }
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
