// Time Complexity of O(n) and space complexity of O(n)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int duplicate(vector<int>& arr)
{
    int a[arr.size()-1];
    for (int i=0; i<arr.size()-1; i++)
    {
        a[i] = 0;
    }
    
    for(int i=0;i<arr.size();i++)
    {
        a[arr[i]-1]++;
    }
    
    for (int i=0; i<arr.size()-1; i++)
    {
        if(a[i] >= 2)
            return i+1;
    }
    return 0;
}

// Using Unordered Set
// TC : O(n) and SC : O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> s;
    
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                return nums[i];
            }
            s.insert(nums[i]);
        }
        
        return 0;
    }
};


int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    int temp;
    
    for (int i=0; i<n; i++)                // input
    {
        cin>>temp;
        arr.push_back(temp);
    }
    
    cout<<duplicate(arr);
    return 0;
}
