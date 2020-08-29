// Time Complexity of O(nlogn) and space complexity of O(1)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int duplicate(vector<int> & arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i] == arr[i+1])
            return arr[i];
    }
    return 0;
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
    
    sort(arr.begin(), arr.end());
    cout<<duplicate(arr);
    return 0;
}
