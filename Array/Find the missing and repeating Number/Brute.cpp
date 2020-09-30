// O(nlogn) is the Time Complexity incurred during the sort process
// Sorted the Array and then found the missing and repeating element
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

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
            cin>>temp;
            Arr[j] = temp;
        }
        
        sort(Arr ,Arr + N);
        missing_duplicate(Arr, N);
    }
    return 0;
}
