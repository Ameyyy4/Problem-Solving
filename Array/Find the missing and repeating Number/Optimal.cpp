// Approach 1
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void missing_duplicate(int *Arr, int Size)
{
    long double sum = 0;
    long double sum_square = 0;
    
    sum = Size*(Size+1)/2;
    
    sum_square = Size*(Size+1)*(2*Size + 1)/6;
    
    for (int i=0; i<Size; i++)
    {
        sum -= Arr[i];
        sum_square -= Arr[i]*Arr[i];
    }
    
    long double M = sum_square/sum;
    long double D = M;
    M = M + sum;
    M = M/2;
    D = D - sum;
    D = D/2;
    cout<<D<<" "<<M<<endl;

    return ;
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

