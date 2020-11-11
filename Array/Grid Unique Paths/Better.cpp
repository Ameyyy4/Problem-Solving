// DP Soln
// O(m*n) TC as well as SC

class Solution {
public:
    
    int uniquePaths(int m, int n, int& dp[][n])
    {
        
        if(m == 1 || n == 1)
        {
            dp[m][n] = 1;
            return dp[m][n];
        }
        if(dp[m][n] != -1)
            return dp[m][n];
        else
            dp[m][n] = uniquePaths(m-1,n,dp) + uniquePaths(m,n-1,dp) ;
        return dp[m][n];
    }
    
};
