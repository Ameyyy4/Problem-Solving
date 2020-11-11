// TC:O(numRows*numRows) SC:O(1){Didnot consider the size of the pascal triangle}
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal;
        for(int i=0;i<numRows;i++)
        {
            vector<int> row(i+1);
            pascal.push_back(row);
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    pascal[i][j] = 1;
                else
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};
