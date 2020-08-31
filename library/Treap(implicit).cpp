/************implicit Treap***************/
/**
2. Treap as Interval Tree(1 based) With Insert and Remove Operation at any position
3. The key(BST Value) is not explicitly stored and determined in the runtime.
4. That's why called implicit treap
5. **/
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int prior,sz;
    int val; ///value stored in the array
    int sum; ///whatever info you want to maintain in segment tree for each node
    int lazy; ///whatever lazy update you want to do
    struct node *l,*r,*p;
} node;
typedef node* pnode;
pnode Treap;
inline int getSize(pnode t){ return t?t->sz:0; }
inline int get_sum(pnode t){ return t?t->sum:0; }
inline void lazyUpdate(pnode t){
    if(!t || !t->lazy)return;
    t->val += t->lazy;
    t->sum += t->lazy*getSize(t);
    if(t->l) t->l->lazy += t->lazy;
    if(t->r) t->r->lazy += t->lazy;
    t->lazy=0;
}
/// operation of segment tree and size,parent update
inline void operation(pnode t) {
    if(!t)return;
    lazyUpdate(t->l); lazyUpdate(t->r); ///imp:propagate lazy before combining t->l,t->r;
    t->sz=getSize(t->l)+1+getSize(t->r);
    t->sum = get_sum(t->l) + t->val + get_sum(t->r); /// updateing sum
    if(t->l) t->l->p = t;
    if(t->r) t->r->p = t;
}
/// The subarray[1:pos] is saved in node l, the rest in r
/// add --> Number of nodes that are not in t's subtree and has index less that t
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t) return void( l = r = NULL) ;
    lazyUpdate(t);
    int curr_pos = add + getSize(t->l)+1;
    if(curr_pos<=pos) split(t->r,t->r,r,pos,curr_pos),l=t;
    else split(t->l,l,t->l,pos,add),r=t;
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){
    lazyUpdate(l); lazyUpdate(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r) , t = l ;
    else merge(r->l,l,r->l) , t = r ;
    operation(t);
}
pnode newNode(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior = rand();
    ret->sz = 1;
    ret->val = ret->sum = val;
    ret->lazy = 0;
    ret->p = ret->l = ret->r = NULL;
    return ret;
}
///changes the value of the node at position id to val
inline void point_update(pnode &t,int id,int val) {
    int sz = getSize(t->l);
    if( sz == (id-1) ) {
        t->val = val;
        pnode cur = t;
        while(cur!=NULL) operation(cur), cur = cur->p;
    }
    else if(sz < (id-1) ) point_update(t->r,id - sz - 1,val);
    else point_update(t->l,id,val);
}
/***
* changes the value of the node at position id to val
* Slower
* Parent er track na rakhle use kora lagte pare
void point_update(pnode &t,int id,int val){
    pnode L,mid,R;
    split(t,L,mid,id-1);
    split(mid,t,R,1);
    t->val = val;
    merge(mid,L,t);
    merge(t,mid,R);
}
***/
/// deletes the node at position id
void remove(pnode &t,int id){
    pnode L,mid,R,X;
    split(t,L,mid,id-1);
    split(mid,X,R,1);
    delete X;
    merge(t,L,R);
}
///inserts a node at position id having array value = val
void insert(pnode &t,int id,int val){
    pnode L,R,mid;
    pnode it = newNode(val);
    split(t,L,R,id-1);
    merge(mid,L,it);
    merge(t,mid,R);
}
/// add val to all the nodes [i:j]
void range_update(pnode t,int i,int j,int val){
    pnode L,M,R;
    split(t,L,M,i-1);
    split(M,t,R,j-i+1);
    t->lazy += val;
    merge(M,L,t);
    merge(t,M,R);
}
/// range query [i:j]
int range_query(pnode t,int i,int j){
    pnode L,M,R;
    split(t,L,M,i-1);
    split(M,t,R,j-i+1);
    int ans = t->sum;
    merge(M,L,t);
    merge(t,M,R);
    return ans;
}
/// Freeing memory after each test case
void Delete(pnode &t){
    if(!t) return;
    if(t->l) Delete(t->l);
    if(t->r) Delete(t->r);
    delete(t);
    t = NULL;
}
///print Treap in order
void printTreap(pnode t){
    if(!t){return;}
    if(t->l){
        printTreap(t->l);
    }
    printf("%d ", t->val);
    if(t->r){
        printTreap(t->r);
    }
}
int main(){
    int n = 5, ara[10];
    for(int i=1; i<=n; i++){
        scanf("%d", &ara[i]);
        merge(Treap,Treap,newNode(ara[i]));
//            insert(Treap, i, ara[i]);
        printTreap(Treap); printf("\n");
    }
    remove(Treap, 2);
}
