// Leetcode Question
// Special Case of null that is matrix.size() = 0
// Case : [], 0
// TC : O(row+col) soln
// SC : O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() == 0)
        return 0;
    int R_index = 0;
    int C_index = matrix[0].size() - 1;
    while(R_index<matrix.size() && C_index>-1)
    {
        if(target == matrix[R_index][C_index])
        {
            return 1;
        }
        if(target > matrix[R_index][C_index])
        {
            R_index++;
            continue;
        }
        if(target < matrix[R_index][C_index])
        {
            C_index--;
            continue;
        }
    }
    if(R_index == matrix.size() || C_index == -1)
    {
        return 0;
    }
    return 1;
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

