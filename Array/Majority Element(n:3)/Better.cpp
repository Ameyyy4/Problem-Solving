// Time Complexity of O(nlogn) and space complexity of O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<int> majority;
    
        if(n == 0)
            return nums;
    
        sort(nums.begin(),nums.end());
        
        int index1, index2;
        index1 = 0;
        index2 = 1;
        int count = 1;
        
        while(index2 != n)
        {
            if(nums[index1] == nums[index2])
            {
                count++;
                index2++;
            }
            else
            {
                if(count>n/3)
                    majority.push_back(nums[index1]);
                index1 = index2;
                index2++;
                count = 1;
            }
        }
        if(count > n/3)
            majority.push_back(nums[n-1]);
        
        return majority;
    }
    
};
// O(n) TC and O(n) SC
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> majority;
        int n = (int) nums.size();
        if(n == 1)
            return nums;
        int index = 0;
        unordered_map<int,int> m;
        while(index!=n)
        {
            m[nums[index]]++;
            if(m[nums[index]] > n/3)
            {
                if(majority.empty())
                    majority.push_back(nums[index]);
                else
                {
                    if(majority[0] != nums[index])
                    {
                        majority.push_back(nums[index]);
                        return majority;
                    }
                }
            }
            index++;
        }
        return majority;
        
    }
    
};
