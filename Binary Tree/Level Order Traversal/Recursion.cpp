
int findheight(Node* node)
{
    if(node == NULL)
        return 0;
    else
    {
        int l_h = findheight(node->left);
        int r_h = findheight(node->right);
        
        if(l_h>r_h)
            return l_h+1;
        else
            return r_h+1;
    }
}
vector<int> allelementwithheight(Node* node, int h)
{
    vector<int> temp;
    if(!node)
        return temp;
    if(h == 1)
    {
        temp.push_back(node->data);
        return temp;
    }
    else
    {
        vector<int> temp1 = allelementwithheight(node->left, h-1);
        vector<int> temp2 = allelementwithheight(node->right, h-1);
        
        temp1.insert(temp1.end(), temp2.begin(), temp2.end());
        return temp1;
    }
}
//You are required to complete this method
vector<int> levelOrder(Node* node)
{
   // Firstly find the height of the tree
   vector<int> L;
   
   int max = findheight(node); // Stores the height of tree in max
   
   int h = 1;
   // add the elements of a particular height and then increase height till max
   while(h<=max)
   {
       vector<int> temp = allelementwithheight(node, h);
       // Temp stores all element of given h and then insert in L
       L.insert(L.end(), temp.begin(), temp.end());
       
       h++;
   }
   return L;
}
