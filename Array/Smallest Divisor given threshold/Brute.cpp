// TC : O(n*n) SC : O(1)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        sort(nums.begin(), nums.end());
        int max = nums[(int)nums.size()-1];
        int remain = threshold - (int)nums.size();
        int sum = 0;
        int divisor = max-1;
        
        while(sum<=remain && divisor>0)
        {
            sum = 0;
            // Find the correct index using binary_search
            int pos = upper_bound(nums.begin(), nums.end(), divisor) - nums.begin();
            for(int i=pos;i<(int)nums.size();i++)
            {
                sum += ceil((double)nums[i]/divisor)-1;
            }
            divisor--;
        }
        
        if(divisor == 0)
        {
            if(sum>remain)
                return 2;
            else
                return 1;
        }
        return divisor+2;
    }
};
