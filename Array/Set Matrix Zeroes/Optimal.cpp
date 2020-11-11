// Determining the states of any position based on its column and row
// row0 variable stores the state of the 1st row
// TC : O(n*m) SC : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int row0 = 1;
        int row = (int)matrix.size();
        int col = (int)matrix[0].size();
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i==0)
                {
                    if(matrix[i][j] == 0)
                        row0 = 0;
                }
                else
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        
        for(int j=col-1;j>=0;j--)
        {
            for(int i=row-1;i>=1;i--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(row0 == 0)
                matrix[0][j] = 0;
        }
        return ;
    }
};
