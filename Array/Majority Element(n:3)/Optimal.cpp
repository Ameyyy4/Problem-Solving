// Boyer - Moore Voting Algo
// TC : O(n)
// SC : O(1)
/*  Boyer-Moore Majority Vote algorithm generalization to elements appear more than floor(n/k) times
    https://leetcode.com/problems/majority-element-ii/discuss/63522/Boyer-Moore-Majority-Vote-algorithm-generalization
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> p;
        int num1 = -1;
        int num2 = -1;
        int c1 = 0;
        int c2 = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == num1)
                c1++;
            else if(nums[i] == num2)
                c2++;
            else if(c1 == 0)
            {
                num1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0)
            {
                num2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == num1)
                c1++;
            else if(nums[i] == num2)
                c2++;
        }
        
        if(c1>(n/3))
            p.push_back(num1);
        if(c2>(n/3))
            p.push_back(num2);
        return p;
    }
};
