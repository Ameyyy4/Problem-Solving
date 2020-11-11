// Used recursion
// O(nlogn) tc 
vector <int> postOrder(Node* root)
{
  // Your code here
        vector<int> r;
        if (root == NULL)
        {
            return r;
        }
        
        vector<int> x;
        x = postOrder(root->left);
        r.insert(r.end(), x.begin(), x.end());
        x = postOrder(root->right);
        r.insert(r.end(), x.begin(), x.end());
        r.push_back(root->data);
        
        return r;
}
