// O(n*n) Time Approach
// O(1) Space Approach
class Solution {
public:
    void transpose(vector<vector<int>>& matrix, int i, int j)
    {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
        return ;
    }
    void swap(vector<vector<int>>& matrix, int i, int z)
    {
        int n = (int)matrix[i].size();
        int temp = matrix[i][z];
        matrix[i][z] = matrix[i][n-1-z];
        matrix[i][n-1-z] = temp;
        return ;
    }
    void rotate(vector<vector<int>>& matrix)
    {
        for(int i=0;i<(int)matrix.size();i++)
        {
            for(int j=i+1;j<(int)matrix[i].size();j++)
            {
                transpose(matrix,i,j);
            }
            for(int z=0;z<(int)matrix[i].size()/2;z++)
            {
                swap(matrix,i,z);
            }
        }
        return ;
    }
};
