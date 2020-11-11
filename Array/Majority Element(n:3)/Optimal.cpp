// Boyer - Moore Voting Algo
// TC : O(n)
// SC : O(1)
/*  Boyer-Moore Majority Vote algorithm generalization to elements appear more than floor(n/k) times
    https://leetcode.com/problems/majority-element-ii/discuss/63522/Boyer-Moore-Majority-Vote-algorithm-generalization
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> majority;
        int nums1 = -1;
        int nums2 = -2;
        int count1 = 0;
        int count2 = 0;
        int n = (int) nums.size();
        if(n == 1)
            return nums;
        int index = 0;
        
        while(index != n)
        {
            if(nums1 == nums[index])
            {
                count1++;
                index++;
            }
            else if(nums2 == nums[index])
            {
                count2++;
                index++;
            }
            else if(count1 == 0)
            {
                nums1 = nums[index];
                index++;
                count1++;
            }
            else if(count2 == 0)
            {
                nums2 = nums[index];
                index++;
                count2++;
            }
            else
            {
                count1--;
                count2--;
                index++;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums1 == nums[i])
                count1++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums2 == nums[i])
                count2++;
        }
        if(count1>n/3)
            majority.push_back(nums1);
        if(count2>n/3)
            majority.push_back(nums2);
        return majority;
        
    }
    
};
