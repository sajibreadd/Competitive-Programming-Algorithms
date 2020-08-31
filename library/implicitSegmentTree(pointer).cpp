/****implicit segment tree with pointer range update range sum ****/
/***problem is range update and range query*******/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int sum, lazy;
    node *left, *right;
    node(){}
    node(int value){
        sum = value;
        lazy = 0;//this should be initialized according to the problem
        left = right = NULL;
    }
};
int n;//space
node *root;
void lazyUpdate(node *cur, int lo, int hi, int v){
    cur->sum += (hi - lo + 1)*v;
}
void pushDown(node *cur, int lo, int hi){
    int mid = (lo + hi)/2;
    cur->left->lazy += cur->lazy;
    cur->right->lazy += cur->lazy;
    lazyUpdate(cur->left, lo, mid, cur->lazy);
    lazyUpdate(cur->right, mid + 1, hi, cur->lazy);
    cur->lazy = 0;
}
void mrg(node *cur){
    cur->sum = cur ->left->sum + cur->right->sum;
}
void update(int lo, int hi, node *cur, int l, int r, int v){
    int i, j, mid = (lo + hi)/2;
    if(l <= lo && r >= hi){
        cur->lazy += v;
        lazyUpdate(cur, lo, hi, v);
        return;
    }
    else if(l > hi || r < lo){return;}
    else{
        if(cur->left == NULL){cur->left = new node(0);}
        if(cur->right == NULL){cur->right = new node(0);}
        pushDown(cur, lo, hi);
        update(lo, mid, cur->left, l, r, v);
        update(mid + 1, hi, cur->right, l, r, v);
        mrg(cur);
    }
}
int query(int lo, int hi, node *cur, int l, int r){
    int i, j, mid =(lo + hi)/2, s1, s2;
    if(l <= lo && r >= hi){
        return cur->sum;
    }
    else if(l > hi || r < lo){
        return 0;
    }
    else{
        if(cur->left == NULL){cur->left = new node(0);}
        if(cur->right == NULL){cur->right = new node(0);}
        pushDown(cur, lo, hi);
        s1 = query(lo, mid, cur->left, l, r);
        s2 = query(mid + 1, hi, cur->right, l, r);
        mrg(cur);
        return s1 + s2;
    }
}
void dlt(node *cur){
    if(cur->left == NULL && cur->right == NULL){
        delete(cur);
        return;
    }
    else{
        if(cur->left != NULL){
            dlt(cur->left);
        }
        else{
            dlt(cur->right);
        }
        delete(cur);
    }
}
int main(){
    int i, j;
    root = new node(0);
    n = 10;
    update(0, n, root, 2, 5, 3);
    update(0, n, root, 4, 6, 2);
    int s= query(0, n, root, 5, 6);
    dlt(root);
    printf("%d\n", s);
}
