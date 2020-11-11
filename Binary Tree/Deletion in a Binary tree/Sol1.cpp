
void searchandreplacenode(Node* root,int key,int val)
{
    Node* a = newNode(0);
    a->left = root;
    a->right = NULL;
    
    queue<Node*> q;
    q.push(a);
    while(!q.empty())
    {
        Node* root1 = q.front();
        q.pop();
        
        // check if any of the child is equal to val or not
        if(root1->left && root1->left->data == key)
        { root1->left->data = val; break; }
        else if(root1->right && root1->right->data == key)
        { root1->right->data = val; break; }
        
        if(root1->left)
            q.push(root1->left);
        if(root1->right)
            q.push(root1->right);
    }
    
}
void removenode(Node* root,int val)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* root1 = q.front();
        q.pop();
        
        // check if any of the child is equal to val or not
        if(root1->left && root1->left->data == val)
        { root1->left = NULL; break; }
        else if(root1->right && root1->right->data == val)
        { root1->right = NULL; break; }
        
        if(root1->left)
            q.push(root1->left);
        if(root1->right)
            q.push(root1->right);
    }
    
}
void levelorder(Node* root, int & val)
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* root1 = q.front();
        val = root1->data;
        q.pop();
        
        if(root1->left)
            q.push(root1->left);
        if(root1->right)
            q.push(root1->right);
    }
    // cout<<val<<endl;
}

void deletionBT(struct Node* root, int key)
{
    if(!root)
        return;
    Node* root1 = root;
    int val;
    
    levelorder(root,val);
    removenode(root,val);
    searchandreplacenode(root,key,val);
    
    return;
}

