// O(n*n) Time Complexity and O(1) Space Complexity

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i,j;
        i = j = 0;
        while(i!=(int)nums.size() || j!=(int)nums.size())
        {
            if(j == (int)nums.size())
            {
                if(j-i-1>0)
                {
                    nums.erase(nums.begin()+i+1,nums.begin()+j);
                }
                i = i+1;
                j = i;
            }
            else
            {
                if(nums[i] == nums[j])
                {
                    j++;
                }
                else
                {
                    if(j-i-1>0)
                    {
                        nums.erase(nums.begin()+i+1,nums.begin()+j);
                    }
                    i = i+1;
                    j = i;
                }
            }
        }
        return (int)nums.size();
    }
};
