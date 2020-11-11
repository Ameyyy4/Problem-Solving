// O(n*n) time approach
// O(n*n) space approach
class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix)
    {
        int n = (int)matrix.size();
        vector<vector<int>> rotated_m(n);
        
        for(int j=0;j<n;j++)
        {
            for(int i=n-1;i>=0;i--)
            {
                rotated_m[j].push_back(matrix[i][j]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                matrix[i][j] = rotated_m[i][j];
        }
        return ;
    }
};
