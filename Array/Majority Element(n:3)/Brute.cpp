// O(n*n) soln

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int count=1;
        vector<int> p;
        int length=nums.size();
        for (int i=0;i<length;++i) {
            for(int j=i+1;j<length;++j){
                if(nums[i]==nums[j])
                    ++count;
            }
            if(count>length/3)
                p.push_back(nums[i]);
            count=1;
        }
        return p;
    
    }
};
