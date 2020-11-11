
void mirror(Node* node)
{
     if(node == NULL)
        return ;
     // Thus we will swap our pointer at each node
     // For a given node I can point my left pointer to right and right to left
     // Stored the left and right pointers
     
     // go and swap for the right node
     mirror(node->right);
     // go and swap for the left node
     mirror(node->left);
     
     Node* l = node->left;
     Node* r = node->right;
     // Swap the pointer
     node->left = r;
     node->right = l;
     
     return ;
}
