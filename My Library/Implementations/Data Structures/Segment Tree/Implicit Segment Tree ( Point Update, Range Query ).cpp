struct node{
    int sum;
    node *left,*right;
    node(){}
    node(int value){
        sum = value;
        left = right = NULL;
    }
};

void update(node *cur,int st,int ed,int id,int v)
{
    if(id<st || id>ed) return;
    if(id==st && id==ed){
        cur->sum = v;
        return;
    }
    int mid = (st+ed)/2;
    if(cur->left==NULL) cur->left = new node(0);
    if(cur->right==NULL) cur->right = new node(0);
    update(cur->left,st,mid,id,v);
    update(cur->right,mid+1,ed,id,v);
    cur->sum = cur->left->sum + cur->right->sum;
}

int query(node *cur,int st,int ed,int i,int j)
{
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
    update(root,1,n,5,1);
    update(root,1,n,3,1);
    cout << query(root,1,n,1,5) << endl;
    return 0;
}

