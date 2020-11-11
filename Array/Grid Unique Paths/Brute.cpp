// Recursive Soln
// O(2^m) or O(2^n) whichever is less Time Complexity and O(2^m) or O(2^n) whichever is less Space Complexity
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if(m == 1 || n == 1)
            return 1;
        return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
    
};
