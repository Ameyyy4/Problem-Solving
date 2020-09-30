// Time Complexity of O(nlogn) and space complexity of O(n)
/* IMP : https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
 */

class Solution {
public:
    void merge(int s, int m, int e, vector<int> &nums, int & count)
    {
        vector<long long int> k, l;
        for(int i=s;i<=m;i++)
        {
            k.push_back(nums[i]);
        }
        for(int i=m+1;i<=e;i++)
        {
            l.push_back(nums[i]);
        }
        
        int i = s;
        int j = m+1;
        
        while(i<=m && j<=e)
        {
            if(k[i-s]>2*l[j-m-1])
            {
                j++;
                count += m-i+1;
            }
            else
            {
                i++;
            }
        }
        
        i = s;
        j = m+1;
        int index = s;
        
        while(i<=m && j<=e)
        {
            if(k[i-s]>l[j-m-1])
            {
                nums[index] = l[j-m-1];
                index++;
                j++;
            }
            else
            {
                nums[index] = k[i-s];
                index++;
                i++;
            }
        }
        
        if(i == m+1)
        {
            for(int z=j; z<=e;z++,index++)
                nums[index] = l[z-m-1];
        }
        if(j == e+1)
        {
            for(int z=i; z<=m;z++,index++)
                nums[index] = k[z-s];
        }
        
        return ;
    }
    void mergesort(int s, int e, vector<int>& nums, int & count)
    {
        if(s == e)
            return ;
        
        int m = s + (e-s)/2;
        
        mergesort(s,m,nums,count);
        mergesort(m+1,e,nums,count);
        merge(s,m,e,nums,count);
        
        return ;
    }
    int reversePairs(vector<int>& nums)
    {
        if(nums.size() == 0 || nums.size() == 1)
            return 0;
        int count = 0;
        mergesort(0,nums.size()-1,nums,count);
        return count;
    }
};
