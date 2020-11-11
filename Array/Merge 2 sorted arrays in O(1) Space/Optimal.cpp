// Takes up time complexity of O(n*m) and O(1) space complexity
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int gap = ceil((double)(n+m)/2);
   
    while(gap>=1)
    {
        // perform the operation of comparing for each gap and then change the gap value
        
        for(int i1=0,i2=gap;i2<n+m;i1++,i2++)
        {
            if(i2<=n-1)
            {
                if(arr1[i1]>arr1[i2])
                {
                    int temp = arr1[i1];
                    arr1[i1] = arr1[i2];
                    arr1[i2] = temp;
                }
                continue;
            }
            if(i1<=n-1 && i2>n-1)
            {
                if(arr1[i1]>arr2[i2-n])
                {
                    int temp = arr1[i1];
                    arr1[i1] = arr2[i2-n];
                    arr2[i2-n] = temp;
                }
                continue;
            }
            if(i1>n-1)
            {
                if(arr2[i1-n]>arr2[i2-n])
                {
                    int temp = arr2[i1-n];
                    arr2[i1-n] = arr2[i2-n];
                    arr2[i2-n] = temp;
                }
                continue;
            }
        }
        
        if(gap == 1)
            gap = 0;
        else
            gap = ceil((double)gap/2);
    }
    
    return ;
}

int main()
{
    int T_cases;
    cin>>T_cases;
    
    for (int i=0; i<T_cases; i++)
    {
        int n,m;
        cin>>n>>m;
        
        int Arr_n[n];
        int Arr_m[m];
        
        for (int j=0; j<n+m; j++)
        {
            if(j<n)
            {
                cin>>Arr_n[j];
            }
            else
                cin>>Arr_m[j-n];
        }
        
        merge(Arr_n, Arr_m, n, m);
    }
    return 0;
}
