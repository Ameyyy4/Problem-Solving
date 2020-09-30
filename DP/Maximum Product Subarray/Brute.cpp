// TIme Complexity is O(n*n) and Space Complexity is O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int max = nums[0];
        int product;
        for(int i=0;i<nums.size();i++)
        {
            product = nums[i];
            if(product>max)
                max = product;
            for(int j=i+1;j<nums.size();j++)
            {
                product *= nums[j];
                if(product>max)
                    max = product;
            }
        }
        return max;
    }
};
