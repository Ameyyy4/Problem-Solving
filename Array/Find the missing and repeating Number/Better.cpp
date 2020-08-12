#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void missing_duplicate(int *Arr, int Size)
{
    int missing;
    int duplicate;
    
    int space[Size] = {0};
    
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

