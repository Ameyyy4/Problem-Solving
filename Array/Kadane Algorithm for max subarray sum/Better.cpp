// Takes up time complexity of O(n*m) and O(1) space complexity
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(int* Arr_n, int* Arr_m, int n, int m)
{
    int i=0;
    
    int temp_1 = 0;
    while (i<n)
    {
        if(Arr_n[i]>Arr_m[0])
        {
            temp_1 = Arr_n[i];
            Arr_n[i] = Arr_m[0];
            Arr_m[0] = temp_1;
            
            for(int z=1; z<m ;z++)
            {
                temp_1 = Arr_m[z-1];
                if(Arr_m[z-1]>Arr_m[z])
                {
                    temp_1 = Arr_m[z];
                    Arr_m[z] = Arr_m[z-1];
                    Arr_m[z-1] = temp_1;
                }
                else
                    break;
            }
        }
        
        i++;
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
