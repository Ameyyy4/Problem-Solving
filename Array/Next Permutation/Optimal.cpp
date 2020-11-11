// TC : O(n) SC : O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int index = 0;
        int n = (int) nums.size();
        
        for(auto i=n-1;i!=0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                index = i;
                break;
            }
        }
        
        if(index > 0)
        {
            for(auto i=n-1;i!=0;i--)
            {
                if(nums[i]>nums[index-1])
                {
                    int tm = nums[i];
                    nums[i] = nums[index-1];
                    nums[index-1] = tm;
                    break;
                }
            }
        }
        
        sort(nums.begin()+index, nums.end());
        
        
        
        return;
    }
};
