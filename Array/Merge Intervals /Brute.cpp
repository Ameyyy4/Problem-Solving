// Time Complexity of O(n^2) and space complexity of O(1)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int duplicate(vector<int> & arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        for (int j=i+1; j<arr.size(); j++)
        {
            if(arr[i] == arr[j])
                return arr[i];
        }
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
    
    cout<<duplicate(arr);
    return 0;
}
