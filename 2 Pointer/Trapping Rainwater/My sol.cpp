// MY SOLUTION
// PASSED 144/320 TEST CASES

class Solution {
public:
    int trap(vector<int>& height)
    {
        int trap_water = 0;
        int n = height.size();
        vector<int> sum(n);
        int i = 1;
        
        while(i<n)
        {
            if(i==0)
                sum[i] = height[i];
            sum[i] = sum[i-1] + height[i];
            i++;
        }
        
        i = 0;
        
        while(i<n-1)
        {
            bool did_increment = false;
            int j = i+1;
            while(j<n)
            {
                if(height[i]<=height[j])
                {
                    trap_water += (j-i-1)*height[i] - sum[j-1] + sum[i];
                    i = j;
                    did_increment = true;
                }
                j++;
            }
            if(!did_increment)
                i++;
        }
        return trap_water;
    }
};
