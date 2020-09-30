// Space Complexity is O(N) and Time Complexity is O(N)
// Used a second array to store the frequency of the values
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void missing_duplicate(int *Arr, int Size)
{
    int missing;
    int duplicate;
    
    int space[Size];
    
    for (int i=0; i<Size; i++)
    {
        space[i] = 0;
    }
    
    for (int i=0; i<Size; i++)
    {
        space[Arr[i]-1]++;
        if(space[Arr[i]-1] == 2)
            duplicate = Arr[i];
    }
    
    for (int i=0; i<Size; i++)
    {
        if(space[i] == 0)
        {
            missing = i+1;
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
        
        missing_duplicate(Arr, N);
    }
    return 0;
}

