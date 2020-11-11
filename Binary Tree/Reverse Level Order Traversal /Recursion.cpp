
int findheight(Node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int h_l = findheight(root->left);
        int h_r = findheight(root->right);
        
        if(h_l>h_r)
            return h_l + 1;
        else
            return h_r + 1;
    }
}
vector<int>allelementath(Node *root, int h)
{
    if(h == 1 || !root)
    {
        vector<int> temp;
        if(root)
        {temp.push_back(root->data);}
        return temp;
    }
    else
    {
        vector<int> l = allelementath(root->left, h-1);
        vector<int> r = allelementath(root->right, h-1);
        l.insert(l.end(), r.begin(), r.end());
        
        return l;
    }
}
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> R;
    int h = findheight(root);
    //cout<<h<<endl;
    if(h == 0)
    {
        return R;
    }
    else
    {
        while(h>0)
        {
            vector<int> temp = allelementath(root, h);
            R.insert(R.end(), temp.begin(), temp.end());
            h--;
        }
    }
    
    return R;
}
