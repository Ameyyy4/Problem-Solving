// TC : O(n*n) SC : O(1)
int maxSubArray(vector<int>& nums) {
       int n=nums.size();
       int ma=INT_MIN;
       for(int i=0;i<n;i++) {
           int s=0;
           for(int j=i;j<n;j++) {
               s+=nums[j];
               ma = max(ma, s);
           }
       }
       return ma;
   }
