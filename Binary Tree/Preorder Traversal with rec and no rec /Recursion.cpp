// Used recursion
// O(nlogn) tc 
vector <int> preorder(Node* root)
{
  // Your code here
    vector<int> r;
    if (root == NULL) {
        return r;
    }
    
    r.push_back(root->data);
    
    vector<int> x;
    
    if (root->left){
        x = preorder(root->left);
        r.insert(r.end(), x.begin(), x.end());
    }
    if (root->right) {
        x = preorder(root->right);
        r.insert(r.end(), x.begin(), x.end());
    }
    return r;
}
