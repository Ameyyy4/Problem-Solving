/* C++ program to check if a tree
is height-balanced or not */
#include <bits/stdc++.h>
using namespace std;
#define bool int

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node {
public:
    int data;
    node* left;
    node* right;
};

/* The function returns true if root is
balanced else false The second parameter
is to store the height of tree. Initially,
we need to pass a pointer to a location with
value as 0. We can also write a wrapper
over this function */
bool isBalanced(node* root, int &height)
{
    int l_h, r_h;
    l_h = r_h = 0;
    
    if(root == NULL)
    {
        height = 0;
        return 1;
    }
    bool l = isBalanced(root->left, l_h);
    bool r = isBalanced(root->right, r_h);
    
    height = (l_h>r_h?l_h:r_h) + 1;
    
    if(abs(l_h - r_h)>1)
        return 0;
    else
        return l && r;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

// Driver code
int main()
{
    int height = 0;

    /* Constructed binary tree is
            1
            / \
            2 3
            / \ /
            4 5 6
            /
            7
    */
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);

    if (isBalanced(root, height))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}

/* C++ program to check if a tree
is height-balanced or not */
#include <bits/stdc++.h>
using namespace std;
#define bool int

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node {
public:
    int data;
    node* left;
    node* right;
};

/* The function returns true if root is
balanced else false The second parameter
is to store the height of tree. Initially,
we need to pass a pointer to a location with
value as 0. We can also write a wrapper
over this function */
int height(node* root, int &ans)
{
  if(root == NULL)
      return 0;
  int h_l = height(root->left,ans);
  int h_r = height(root->right,ans);
  
  ans = ans && abs(h_l-h_r)<=1;
    
  return (h_l>h_r?h_l:h_r) + 1;
}
bool isBalanced(node* root)
{
    bool ans = true;
    int h = height(root,ans);
  
      return ans;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

// Driver code
int main()
{
    int height = 0;

    /* Constructed binary tree is
            1
            /
            2
            / \
            4 5
            /
            7
    */
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = NULL;
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}

// This is code is contributed by rathbhupendra

