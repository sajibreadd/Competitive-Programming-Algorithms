/********Treap normal****************/
#include <bits/stdc++.h>
#define SZ 10000000
using namespace std;
struct node{
    int prior; /// Heap value generated randomly
    int key; /// BST value
    int sz; /// Subtree Size(including this node)
    int sum; /// This bst maintains the sum of it's child nodes
    struct node *l,*r,*p;
};
node *Treap;
inline int getSize(node *cur){return cur ? cur->sz:0;}
inline int getSum(node *cur){return cur ? cur->sum:0;}
inline void update(node *cur){
    if(!cur){return;}
    if(cur->l){cur->l->p = cur;}
    if(cur->r){cur->r->p = cur;}
    cur->sz = getSize(cur->l) + 1 + getSize(cur->r);
    cur->sum = getSum(cur->l) + cur->key + getSum(cur->r);
}
inline node *newNode(int key){
    node *ret = (node*)malloc(sizeof(node));
    ret->sum = ret->key = key;
    ret->sz = 1;
    ret->prior = rand();
    ret->p = ret->l = ret->r = NULL;
    return ret;
}
/// l will contain the nodes having BST value <= key, rest will go to r
void split(node *cur, node* &l, node* &r, int key){
    if(!cur){l = r = NULL;}
    else if(cur->key <= key){split(cur->r, cur->r, r, key), l = cur;}
    else{split(cur->l, l, cur->l, key), r = cur;}
    update(cur);
}
/// lowest value of r has to be > that largest value of l
void merge(node* &cur, node* l, node* r){
    if(!l || !r){cur = l ? l : r;}
    else if(l->prior > r->prior){merge(l->r, l->r, r), cur = l;}
    else{merge(r->l, l, r->l), cur = r;}
    update(cur);
}
/// inserting a new node into BST
void insert(node* &cur, node *it){
    if(!cur){cur = it;}
    else if(it->prior > cur->prior){
        split(cur, it->l, it->r, it->key), cur = it;
    }
    else if(cur->key <= it->key){insert(cur->r, it);}
    else{insert(cur->l, it);}
    update(cur);
}
/// Removing a node having BST value = key
void remove(node* &cur, int key){
    if(!cur){return;}
    else if(cur->key == key){
        node *temp = cur;
        merge(cur, cur->l, cur->r);
        free(temp);
    }
    else if(cur->key < key){remove(cur->r, key);}
    else{remove(cur->l, key);}
    update(cur);
}
/// Deleting the treap, freeing memory
void dlt(node* &cur){
    if(!cur){return;}
    if(cur->l){dlt(cur->l);}
    if(cur->r){dlt(cur->r);}
    delete(cur);
    cur = NULL;
}
///print the whole Treap
void printTreap(node *cur){
    if(!cur){return;}
    printf("%d %d\n", cur->key, cur->prior);
    if(cur->l){printTreap(cur->l);}
    if(cur->r){printTreap(cur->r);}
}
///get the number of elements that is less than the key value
int getLessThan(node *cur, int key){
    if(!cur){return 0;}
    if(key > cur->key){
        return getSize(cur->l) + 1 + getLessThan(cur->r, key);
    }
    else if(key <= cur->key){
        return getLessThan(cur->l, key);
    }
}
///get the number of elements that is less than equal the key value
int getLessThanEqual(node *cur, int key){
    if(!cur){return 0;}
    if(key >= cur->key){
        return getSize(cur->l) + 1 + getLessThan(cur->r, key);
    }
    else if(key < cur->key){
        return getLessThan(cur->l, key);
    }
}
int main(){
    Treap = NULL;
    node *tmp = newNode(2);
    insert(Treap, tmp);
    insert(Treap, newNode(10));
    insert(Treap, newNode(8));
    insert(Treap, newNode(5));
    insert(Treap, newNode(5));
    insert(Treap, newNode(15));
    insert(Treap, newNode(1));
    insert(Treap, newNode(7));
    remove(Treap, 5);
    printTreap(Treap);
}
