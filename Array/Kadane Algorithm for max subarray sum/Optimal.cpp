// Kadane's Algo
// TC : O(n) SC : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int max = INT_MIN;
        
        // Find the maximum element of the array
        for(int i=0;i<nums.size();i++)
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
};
// Divide and Conquer
// TC : O(n) SC : O(1)
// Not understood this algo
int maxSubArray(vector<int>& nums) {
       int ml, mr, sum;
       return maxSubArray(0,nums.size()-1, ml, mr, sum, nums);
   }
   int maxSubArray(int l, int r, int& ml, int& mr, int& sum, vector<int>& nums) {
       if(l==r) return ml = mr = sum = nums[l];
       int mid= (l+r)/2, lml, lmr, lsum, rml, rmr, rsum;
       int ms=maxSubArray(l,mid,lml,lmr,lsum,nums);
       ms=max(ms,maxSubArray(mid+1,r,rml,rmr,rsum,nums));
       ml = max(lml, lsum+rml);
       mr = max(rmr, rsum+lmr);
       sum = lsum+rsum;
       return max(ms,lmr+rml);
   }
