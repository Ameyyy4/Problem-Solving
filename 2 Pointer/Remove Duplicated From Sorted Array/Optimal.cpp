//O(n) Approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i;
        int n = (int)nums.size();
        int count = 0;
        for(i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
                count++;
            else
                nums[i-count] = nums[i];
        }
        return n - count;
    }
};
