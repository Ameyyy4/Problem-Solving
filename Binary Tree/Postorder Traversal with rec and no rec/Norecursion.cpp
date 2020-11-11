
#include <bits/stdc++.h>
/* Driver program to test above functions*/
struct Node{
    int data;
    Node* left,right;
    
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
}

void inOrder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
    
    while(curr != NULL || s.empty() == false)
    {
        while(curr!=NULL)      // traverse leftwards till NULL
        {
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        curr = curr->right;
        if(curr)
            continue;
        curr = s.top();
        s.pop();
        cout<<curr->data<<endl;
        curr = NULL;
    }
    
    return ;
}

int main()
{

    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct Node *root = new Node(1);
    root->left     = new Node(2);
    root->right     = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    return 0;
}
