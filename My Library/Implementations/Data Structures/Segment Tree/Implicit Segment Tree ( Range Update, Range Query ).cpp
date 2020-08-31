struct node{
    int sum,lazy;
    node *left,*right;
    node(){}
    node(int value){
        sum = value;
        lazy = 0;
        left = right = NULL;
    }
};

void lazyUpdate(node *cur,int st,int ed)
{
    if(cur->lazy!=0){
        cur->sum += ((ed-st+1)*cur->lazy);
        if(st!=ed){
            if(cur->left==NULL) cur->left = new node(0);
            if(cur->right==NULL) cur->right = new node(0);
            cur->left->lazy += cur->lazy;
            cur->right->lazy += cur->lazy;
        }
        cur->lazy = 0;
    }
}

void update(node *cur,int st,int ed,int i,int j,int v){
    lazyUpdate(cur,st,ed);
    if(st>j || ed<i) return;
    if(st>=i && ed<=j){
        cur->lazy += v;
        lazyUpdate(cur,st,ed);
        return;
    }
    int mid = (st+ed)/2;
    if(cur->left==NULL) cur->left = new node(0);
    if(cur->right==NULL) cur->right = new node(0);
    update(cur->left,st,mid,i,j,v);
    update(cur->right,mid+1,ed,i,j,v);
    cur->sum = cur->left->sum + cur->right->sum;
}

int query(node *cur,int st,int ed,int i,int j){
    lazyUpdate(cur,st,ed);
    if(st>=i && ed<=j) return cur->sum;
    int mid = (st+ed)/2;
    if(cur->left==NULL) cur->left = new node(0);
    if(cur->right==NULL) cur->right = new node(0);
    if(mid<i) return query(cur->right,mid+1,ed,i,j);
    else if(mid>=j) return query(cur->left,st,mid,i,j);
    else return query(cur->right,mid+1,ed,i,j)+query(cur->left,st,mid,i,j);;
}

int main()
{
    int n = 1000000000;
    node *root = new node(0);
    update(root,1,n,1,5,1);
    update(root,1,n,4,10,1);
    update(root,1,n,9,14,1);
    cout << query(root,1,n,1,20) << endl;
    return 0;
}

