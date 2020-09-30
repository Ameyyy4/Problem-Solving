// Time Complexity of O(n) and space complexity of O(1)
// 1 pass Algo
// Dutch National Flag Algorithm
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void sort(vector<int> & arr, int s, int e)
{
    int low = s;
    int mid = s;
    int high = e;
    
    while(mid<=high)
    {
        if(arr[mid] == 0)
        {
            int temp;
            temp = 0;
            arr[mid] = arr[low];
            arr[low] = temp;
            mid++;
            low++;
            continue;
        }
        if(arr[mid] == 2)
        {
            int temp;
            temp = 2;
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
            continue;
        }
        if(arr[mid] == 1)
        {
            mid++;
            continue;
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
    
    sort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
     
}
