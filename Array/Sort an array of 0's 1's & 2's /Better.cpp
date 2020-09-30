// Time Complexity of O(n) and space complexity of O(1)
// 2 pass algo where first pass used for counting and second pass is used for assigning the values
// Counting Sort Algo
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void count_sort(vector<int> & arr, int s, int e)
{
    int a0 = 0;
    int a1 = 0;
    int a2 = 0;
    
    for (int i=s; i<=e; i++)
    {
        if(arr[i] == 0)
            a0++;
        if(arr[i] == 1)
            a1++;
        if(arr[i] == 2)
            a2++;
    }
    
    for (int i=s; i<=e; i++)
    {
        if(a0>0)
        {
            arr[i] = 0;
            a0--;
        }
        else
        {
            if(a1>0)
            {
                arr[i] = 1;
                a1--;
            }
            else
            {
                arr[i] = 2;
                a2--;
            }
        }
    }
    
    return;
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
    
    count_sort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
     
}
