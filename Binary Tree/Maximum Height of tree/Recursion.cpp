// O(n) solution
// Recursive algo
class Solution{
    public:
    int height(struct Node* node)
    {
        if(node == NULL)
            return 0;
        // height of tree is max of left subtree and rightsubtree;
        int height_l = height(node->left);
        int height_r = height(node->right);
        int h = 1 + (height_l>height_r?height_l:height_r);
        
        return h;
    }
};
