// Time Complexity of O(nlogn) and space complexity of O(n)
// merge sort algorithm
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
void merge(vector<int> & arr, int s, int m, int e)
{
    int arr1[m-s];
    int arr2[e-m+1];
    
    for (int i=s; i<=e; i++)
    {
        if(i<m)
            arr1[i-s] = arr[i];
        if(i>=m)
            arr2[i-m] = arr[i];
    }
    
    int index1 = 0;
    int index2 = 0;
    int i = s;
    
    while(index1<=m-s-1 && index2<=e-m)
    {
        if(arr1[index1]<arr2[index2])
        {
            arr[i] = arr1[index1];
            i++;
            index1++;
        }
        else
        {
            arr[i] = arr2[index2];
            i++;
            index2++;
        }
    }
    
    if(index1 == m-s)
    {
        for (int j = i; j<=e; j++)
        {
            arr[j] = arr2[index2];
            index2++;
        }
    }
    else
    {
        for (int j = i; j<=e; j++)
        {
            arr[j] = arr1[index1];
            index1++;
        }
    }
}

void mergesort(vector<int> & arr, int s, int e)
{
    if(s == e)
        return;
    
    mergesort(arr, s, (s+e)/2);
    mergesort(arr, (s+e)/2 + 1, e);
    merge(arr, s, (s+e)/2 + 1, e);
    
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
    
    mergesort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
     
}
