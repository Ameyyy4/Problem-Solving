// Time Complexity of O(nlogn) and space complexity of O(1)
class Solution {
public:
    int majorityElement(vector<int>& a)
    {
        sort(a.begin(),a.end());
        int size = (int)a.size();
        
        return a[size/2];
    }
};
// O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    int majorityElement(vector<int>& a)
    {
        unordered_map<int,int> m;
        int n = (int) a.size();
        
        for(int i=0; i<n; i++)
        {
            m[a[i]]++;
            if(m[a[i]] > n/2)
                return a[i];
        }
        return 0;
    }
};
// O(nlogn) TC and O(1) SC
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int m = l + (r - l) / 2, lm = majority(nums, l, m), rm = majority(nums, m + 1, r);
        if (lm == rm) {
            return lm;
        }
        return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm;
    }
};
// More Solns( Randomization, Hash Table, Divide and Conquer) at
// https://leetcode.com/problems/majority-element/discuss/51612/C%2B%2B-6-Solutions
