// O(n*n) TC
// O(n*n) SC for storing the 2d triplet vector
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j,z;
        vector<vector<int>> triplet;
        int n = (int)nums.size();
        
        while(i<=n-3)
        {
            int sum = nums[i];
            j = i+1;
            z = n-1;
            while(j<z)
            {
                sum += nums[j] + nums[z];
                if(sum<0)
                    j++;
                else if(sum>0)
                    z--;
                else
                {
                    vector<int> vec(3);
                    vec[0] = nums[i];
                    vec[1] = nums[j];
                    vec[2] = nums[z];
                    triplet.push_back(vec);
                    z = n-1;
                    while(j<z && nums[j]==vec[1])
                        j++;
                }
                
                sum = nums[i];
            }
            while(i<=n-3 && nums[i] == sum)
                i++;
        }
        
        return triplet;
    }
};
