
int height(Node* root)
{
    if(root == NULL)
        return 0;
    else
    {
        int h_l = height(root->left);
        int h_r = height(root->right);
        
        if(h_l>h_r)
            return h_l+1;
        else
            return h_r+1;
    }
}
bool isBalanced(Node *root)
{
    if(root == NULL)
        return true;
    // if left subtree and right subtree are balanced and height difference is less than one then return true
    bool l = isBalanced(root->left);
    bool r = isBalanced(root->right);
    int h_l = height(root->left);
    int h_r = height(root->right);
    
    if(l && r)
    {
        if(abs(h_l-h_r)<=1)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

