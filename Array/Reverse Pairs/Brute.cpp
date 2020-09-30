// Time Complexity of O(n^2) and space complexity of O(1)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] > 2*nums[j])
                    count++;
            }
        }
        return count;
    }
};
