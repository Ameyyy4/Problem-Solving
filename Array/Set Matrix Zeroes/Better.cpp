// Stored the row number & column number for the zeroes in the row and column vector
// TC : O(n*m) SC : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<int> row;
        vector<int> col;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        vector<int>::iterator r1;
        vector<int>::iterator c1;
        
        for(r1 = row.begin();r1!=row.end();r1++)
        {
            for(int j=0;j<matrix[*r1].size();j++)
            {
                matrix[*r1][j] = 0;
            }
        }
        
        for(c1 = col.begin();c1!=col.end();c1++)
        {
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][*c1] = 0;
            }
        }
        return ;
    }
};
