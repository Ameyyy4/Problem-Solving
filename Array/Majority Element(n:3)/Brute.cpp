// O(n*n) Time Complexity and O(1) Space Complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<int> majority;
        
        if(n == 0)
            return nums;
        
        for(int i=0;i<n;i++)
        {
            int count = 1;
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] == nums[j])
                    count++;
            }
            if(count>n/3)
            {
                if(majority.empty())
                    majority.push_back(nums[i]);
                else
                {
                    if(majority[0] != nums[i])
                    {
                        majority.push_back(nums[i]);
                        return majority;
                    }
                }
            }
        }
        
        return majority;
    }
    
};
