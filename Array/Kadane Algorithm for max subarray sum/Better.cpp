// Takes up time complexity of O(nlogn) and O(n) space complexity
class Solution {
public:
    
    int midsum(vector<int> &nums, int left, int right)
    {
        int max = INT_MIN;
        
        // Find the maximum element of the array
        for(int i=left;i<=right;i++)
        {
            if(max<nums[i])
                max = nums[i];
        }
        
        if(max<=0)
        {
            return max;
        }
        else
        {
            int sum = 0;
            for(int i=0;i<nums.size();i++)
            {
                sum += nums[i];
                if(sum<0)
                    sum = 0;
                if(sum>max)
                    max = sum;
            }
        }
        
        return max;
    }
    
    int maxsum(vector<int> &nums, int left, int right)
    {
        if(left == right)
            return nums[left];
        
        int S_left = maxsum(nums, left, (left+right)/2);        // Find max sum in left half
        int S_right = maxsum(nums, (left+right)/2 + 1, right);  // Find max_sum in right half
        
        return max(midsum(nums,left,right), max(S_left,S_right));
    }
    
    int maxSubArray(vector<int>& nums)
    {
        return maxsum( nums, 0, nums.size()-1);
    }
};
