
bool isBST(Node* root)
{
    // Your code here
    if(root == NULL)
        return 1;
    // Given tree is BST if right part is BST and Left Part is BST
    // Adding to that all values to right of root must be greater that root value
    // All values to the left of the root must be less than root value
    // we can find the inorder successor of root and inorder predessor of root
    // I root lies within that range then it is BST
    // Check the left and right subtree
    bool l_tree = isBST(root->left);
    bool r_tree = isBST(root->right);
    
    vector<int> vec;
    inorder(root, vec);
    
    if(l_tree && r_tree)
    {
        vector<int>::iterator it;
        it = find(vec.begin(),vec.end(),root->data);
        int index = it - vec.begin();
        
        int size = vec.size();
        if(index+1>=size)
        {
            if(index<1)
                return 1;
            else
            {
                if(vec[index]>vec[index-1])
                    return 1;
                else
                    return 0;
            }
        }
        if(index+1<size)
        {
            if(index<1)
            {
                if(vec[index]<vec[index+1])
                    return 1;
                else
                    return 0;
            }
            else
            {
                if(vec[index]>vec[index-1] && vec[index]<vec[index+1])
                    return 1;
                else
                    return 0;
            }
        }
    }
    else
        return 0;
}

