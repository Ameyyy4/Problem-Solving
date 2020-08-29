// Takes up time complexity of O(n+m) and O(n+m) space complexity
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums, int start_index)
{
    int max_sum = nums[start_index];
    if(start_index == nums.size()-1)
    {
        if(max_sum<0)
            return 0;
        else
            return max_sum;
    }
    
    while(start_index<nums.size())
    {
        if(max_sum<0)
        {
            start_index++;
            if(max_sum<nums[start_index])
            {
                max_sum = nums[start_index];
            }
        }
        else
        {
            start_index++;
            if(nums[start_index]>0)
            {
                max_sum += nums[start_index];
            }
            else
            {
                int temp = maxSubArray(nums, start_index+1);
                
                if(max_sum>0 && nums[start_index]>0 && temp>0)
                {
                    return max_sum + nums[start_index] + temp;
                }
                if(max_sum>0 && nums[start_index]>0 && temp<=0)
                {
                    return max_sum + nums[start_index];
                }
                if(max_sum>0 && nums[start_index]<=0 && temp>0)
                {
                    if(nums[start_index] == 0)
                        return max_sum+temp;
                    else
                    {
                        int t1 = max_sum+nums[start_index]+temp;
                        max_sum = max_sum>t1?max_sum:t1;
                        max_sum = temp>max_sum?temp:max_sum;
                        return max_sum;
                    }
                }
                if(max_sum>0 && nums[start_index]<=0 && temp<=0)
                {
                    return max_sum;
                }
                if(max_sum<=0 && nums[start_index]>0 && temp>0)
                {
                    return nums[start_index] + temp;
                }
                if(max_sum<=0 && nums[start_index]>0 && temp<=0)
                {
                    return nums[start_index];
                }
                if(max_sum<=0 && nums[start_index]<=0 && temp<=0)
                {
                    if(nums[start_index] == 0)
                        return 0;
                    else
                    {
                        int t1 = max_sum+nums[start_index]+temp;
                        max_sum = max_sum>t1?max_sum:t1;
                        max_sum = temp>max_sum?temp:max_sum;
                        return max_sum;
                    }
                }
                if(max_sum<=0 && nums[start_index]<=0 && temp>0)
                {
                    return temp;
                }
            }
        }
    }
    return max_sum;
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> Arr;
    
    int temp=0;
    for (int j=0; j<n; j++)
    {
        cin>>temp;
        Arr.push_back(temp);
    }
    
    maxSubArray(Arr, 0, n-1);
    
    return 0;
}
