// Time Complexity of O(n) and space complexity of O(1)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int duplicate(vector<int> & arr)
{
    int slow;
    int fast;
    slow = fast = arr[0];
    
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while (slow!=fast);
    
    fast = arr[0];
    
    while (slow!=fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
}

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
