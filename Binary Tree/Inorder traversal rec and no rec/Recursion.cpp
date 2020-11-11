// Used recursion
// O(nlogn) tc 
vector<int> inOrder(Node* root)
{
    if(root == NULL)
    {
        vector<int> temp;
        return temp;
    }
    vector<int> arr;
    vector<int> l = inOrder(root->left);
    arr.insert(arr.end(),l.begin(),l.end());
    arr.push_back(root->data);
    vector<int> r = inOrder(root->right);
    arr.insert(arr.end(),r.begin(),r.end());
    
    return arr;
}
