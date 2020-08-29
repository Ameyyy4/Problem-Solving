// Takes up time complexity of O(n*m) and O(1) space complexity
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(int* Arr_n, int* Arr_m, int n, int m)
{
    int gap=0;
    
    if((n+m)%2 == 0)
        gap = (n+m)/2;
    else
        gap = (n+m)/2 + 1;
    
    while(gap>=1)
    {
        int i = 0;
        int j;
        j=i+gap;
        
        while(j<m+n)
        {
            int temp = 0;
            if(j<n)
            {
                if(Arr_n[i]>=Arr_n[j])
                {
                    temp = Arr_n[j];
                    Arr_n[j] = Arr_n[i];
                    Arr_n[i] = temp;
                }
            }
            else if(j>=n && i<n)
            {
                if(Arr_n[i]>=Arr_m[j-n])
                {
                    temp = Arr_m[j-n];
                    Arr_m[j-n] = Arr_n[i];
                    Arr_n[i] = temp;
                }
            }
            else if(j>=n && i>=n)
            {
                if(Arr_m[i-n]>=Arr_m[j-n])
                {
                    temp = Arr_m[j-n];
                    Arr_m[j-n] = Arr_n[i-n];
                    Arr_n[i-n] = temp;
                }
            }
            i++;
            j++;
        }
        for (int j=0; j<n+m; j++)
        {
            if(j<n)
                cout<<Arr_n[j]<<" ";
            else
                cout<<Arr_m[j-n]<<" ";
        }
        cout<<endl;
        if(gap == 1)
            break;
        if(gap%2 == 0)
            gap = gap/2;
        else
            gap = gap/2 + 1;
    }
    
    for (int j=0; j<n+m; j++)
    {
        if(j<n)
            cout<<Arr_n[j]<<" ";
        else
            cout<<Arr_m[j-n]<<" ";
    }
    cout<<endl;
    
    return;
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
