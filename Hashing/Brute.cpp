// a naive approach with TC : O(n^2) and constant space

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> p;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(target-nums[i]==nums[j])
                {
                    p.push_back(i);
                    p.push_back(j);
                    return p;
                }
            }
        }
        return p;
    }
};
