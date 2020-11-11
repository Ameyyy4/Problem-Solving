
int height(Node* node)
{
    if(!node)
        return 0;
    else
    {
        int h_l = height(node->left);
        int h_r = height(node->right);
        
        if(h_l>h_r)
            return h_l+1;
        else
            return h_r+1;
    }
}

int diameter(Node* node)
{
    if(!node)
        return 0;
    if(!node->left && !node->right)
        return 1;
    //int val = 0;
    
    // Diameter of tree = max(Diameter of left, Diameter of right, h(left)+h(right)+1)
    
    int d_l = diameter(node->left);
    int d_r = diameter(node->right);
    int h_l = height(node->left);
    int h_r = height(node->right);
    
    int max1 = d_l>d_r?d_l:d_r;
    int max2 = (h_l + h_r + 1)>max1?(h_l + h_r + 1):max1;
    
    return max2;
}

