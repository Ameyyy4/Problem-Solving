More Good Binary Search Problems
Here are some similar binary search problems.
Also find more explanations.
Good luck and have fun.

Divide Chocolate
Capacity To Ship Packages In N Days
Koko Eating Bananas
Minimize Max Distance to Gas Station
Split Array Largest Sum
// TC : O(nlogn) SC : O(1)
//
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int max = nums[n-1];
        long long int sum = 0;
        int divisor1 = 1;
        int divisor2 = max;
        int divisor = (divisor1+divisor2)/2;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        if(sum<=threshold)
            return 1;
        
        while(true)
        {
            sum = 0;

            for(int i=0;i<n;i++)
            {
                sum += ceil((double)nums[i]/divisor);
            }
            
            if(sum<=threshold)
            {
                divisor2 = divisor;
                divisor = (divisor1+divisor2)/2;
            }
            else
            {
                divisor1 = divisor;
                divisor = (divisor1+divisor2)/2;
            }
            
            if(divisor2 - divisor1 <= 1)
            {
                return divisor2;
            }
        }
        
        return divisor2;
    }
};
