// TC : O(n*n) Approach
// SC : O(1) Approach
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int *findTwoElement(int *arr, int n)
    {
        // code here
        int a[] = {0,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i] == arr[j])
                {
                    a[0] = arr[i];
                    break;
                }
            }
            if(a[0] != 0)
                break;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == arr[j])
                {
                    break;
                }
                else
                {
                    if(j == n-1)
                    {
                        a[1] = i;
                        break;
                    }
                }
            }
            if(a[1] != 0)
                break;
        }
        
        return a;
    }
};

// O(nlogn) is the Time Complexity incurred during the sort process
// Sorted the Array and then found the missing and repeating element

/*
void missing_duplicate(int *Arr, int Size)
{
    int missing;
    int duplicate;
    
    if(Arr[0] != 1)
    {
        missing = 1;
        for (int i=0; i<Size; i++)
        {
            if (Arr[i+1]==Arr[i])
            {
                duplicate = Arr[i];
            }
        }
    }
    else if(Arr[Size-1] != Size)
    {
        missing = Size;
        for (int i=0; i<Size; i++)
        {
            if (Arr[i+1]==Arr[i])
            {
                duplicate = Arr[i];
                break;
            }
        }
    }
    else
    {
        for (int i=0; i<Size; i++)
        {
            if(Arr[i+1]-Arr[i] == 2)
            {
                missing = Arr[i]+1;
            }
            if (Arr[i+1]==Arr[i])
            {
                duplicate = Arr[i];
            }
            if(i == Size-1)
                break;
        }
    }
    
    cout<<duplicate<<" "<<missing<<endl;
}
*/
int main()
{
    int T_cases;
    cin>>T_cases;
    
    for (int i=0; i<T_cases; i++)
    {
        int N;
        cin>>N;
        
        int Arr[N];
        int temp;
        
        for (int j=0; j<N; j++)
        {
            cin>>Arr[i];
        }
        
        //sort(Arr ,Arr + N);
        auto p = findTwoElement(Arr, N);
        
        cout<<p[0]<<" "<<p[1]<<endl;
    }
    return 0;
}

