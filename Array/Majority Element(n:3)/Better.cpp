// Time Complexity of O(nlogn) and space complexity of O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        
        int freq = 1;
        for(int i=1; i<n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                freq++;
                if(freq > n/2)
                    return nums[i];
            }
            else
                freq = 1;
        }
        
        return 0;
    }
};

// More Solns( Randomization, Hash Table, Divide and Conquer) at
// https://leetcode.com/problems/majority-element/discuss/51612/C%2B%2B-6-Solutions
