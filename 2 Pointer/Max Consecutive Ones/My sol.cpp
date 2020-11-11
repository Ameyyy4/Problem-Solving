//O(n) Time Complexity
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int i = 0;
        int n = nums.size();
        int max = 0;
        int consecutive = 0;
        while(i<n)
        {
            if(nums[i] == 1)
            {
                consecutive++;
            }
            else
            {
                consecutive = 0;
            }
            max = max>consecutive?max:consecutive;
            i++;
        }
        return max;
    }
};
