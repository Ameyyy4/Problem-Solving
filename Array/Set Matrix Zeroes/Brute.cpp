// Leetcode Question
// Special Case of null that is matrix.size() = 0
// Case : [], 0
// TC : O(row*col) soln
// SC : O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.empty())  return false;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == target)  return true;
        }
    }
    return false;
}

int main()
{
    //code
    int t;
    cin>>t;
    
    int row;
    int col;
    
    int temp;
    for(int i=0; i<t; i++)
    {
        cin>>row>>col;
        
        vector< vector<int> > matrix(row);
        for(int i=0; i<row; i++)
        {
            matrix[i] = vector<int> (col);
            for(int j = 0; j<matrix[i].size(); j++)
            {
                cin>>temp;
                matrix[i][j] = temp;
            }
        }
        
        cin>>temp;
        cout<<searchmatrix( matrix, temp)<<endl;
    }
    return 0;
     
}

