// Takes up time complexity of O(n+m) and O(n+m) space complexity
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(int* Arr_n, int* Arr_m, int n, int m)
{
    int i=0;
    int j=0;
    vector<int> Arr_combined;
    
    while (i<n && j<m)
    {
        if(Arr_n[i]>Arr_m[j])
        {
            Arr_combined.push_back(Arr_m[j]);
            j++;
            continue;
        }
        else
        {
            Arr_combined.push_back(Arr_n[i]);
            i++;
        }
    }
    
    if(i<n)
    {
        for (int z=i; z<n; z++)
        {
            Arr_combined.push_back(Arr_n[z]);
        }
    }
    else
    {
        for (int z=j; z<m; z++)
        {
            Arr_combined.push_back(Arr_m[z]);
        }
    }
    
    for (int z=0; z<n+m; z++)
    {
        cout<<Arr_combined[z]<<" ";
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
