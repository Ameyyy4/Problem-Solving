// Brute force approach
// O(n^3)
// Does not pass all test cases on leetcode
// 315/318
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        int sum = 0;
        vector<vector<int>> triplet;
        
        for(int i=0;i<n-1;i++)
        {
            sum = nums[i];
            int j = i+1;
            int z = n-1;
            while(j<z)
            {
                sum += nums[j]+nums[z];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    z--;
                }
                else
                {
                    vector<int> new_(3);
                    new_[0] = nums[i];
                    new_[1] = nums[j];
                    new_[2] = nums[z];
                    bool isPresent = find(triplet.begin(),triplet.end(),new_) != triplet.end();
                    if(!isPresent)
                    {
                        triplet.push_back(new_);
                    }
                    j++;z--;
                }
                sum = nums[i];
            }
        }
        return triplet;
    }
};
