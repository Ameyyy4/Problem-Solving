// Time Complexity of O(n*n) and space complexity of O(1)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void print_Sorted(vector<int> &a, int n)
{
    int indicator = 0;
    int curr_loc = n-1;
    
    for(int z = 0;z<n;z++)
    {
        if(a[z] != 0)
        {
            for(int i=z+1;i<n;i++)
            {
                if(a[i] == 0)
                {
                    a[i] = a[z];
                    a[z] = 0;
                    break;
                }
                else
                {
                    if(i == n-1)
                        indicator = 1;
                }
            }
        }
        if(indicator == 1)
        {
            curr_loc = z;
            break;
        }
    }

    for(int z = curr_loc;z<n;z++)
    {
        if(a[z] != 1)
        {
            for(int i=z+1;i<n;i++)
            {
                if(a[i] == 1)
                {
                    a[i] = a[z];
                    a[z] = 1;
                    break;
                }
                else
                {
                    if(i == n-1)
                        indicator = 2;
                }
            }
        }
        if(indicator == 2)
            break;
    }
    
    for(int i = 0; i<n ; i++)
        cout<<a[i]<<" ";
        
    return ;
    
}

int main() {
    //code
    int t;
    int n;
    int temp;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        vector<int> p;
        for(int j = 0;j<n;j++)
        {
            cin>>temp;
            p.push_back(temp);
        }
        
        print_Sorted(p,n);
        cout<<endl;
    }
    return 0;
}

// Time Complexity of O(nlogn) and space complexity of O(n)
// merge sort algorithm

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


