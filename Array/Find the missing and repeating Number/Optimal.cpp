// 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// Approach 1
/*void missing_duplicate(int *Arr, int Size)
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
*/
//Approach 2 - using XOR
void missing_duplicate(int *Arr, int Size)
{
    int p = 0;
    int q = 0;
    for (int i=0; i<Size; i++)
    {
        p = p^Arr[i];
        q = q^(i+1);
    }
    
    int num = p^q;
    
    num = num & ~(num-1);
    
    vector<int> Bucket_1;
    vector<int> Bucket_2;
    
    for (int i=0; i<Size; i++)
    {
        if(Arr[i] & num)
            Bucket_1.push_back(Arr[i]);
        else
            Bucket_2.push_back(Arr[i]);
    }
    
    for (int i=1; i<=Size; i++)
    {
        if(i & num)
            Bucket_1.push_back(i);
        else
            Bucket_2.push_back(i);
    }
    
    int a=0;
    int b=0;
    for(int i=0; i<Bucket_1.size(); i++)
    {
        a = a^(Bucket_1[i]);
    }
    for(int i=0; i<Bucket_2.size(); i++)
    {
        b = b^(Bucket_2[i]);
    }
    for(int i=0;i<Size;i++)
    {
        if(Arr[i] == a)
        {
            cout<<a<<" "<<b<<endl;
            break;
        }
        if(Arr[i] == b)
        {
            cout<<b<<" "<<a<<endl;
            break;
        }
    }
    return ;
}
    
    

//Approach 3 - modification in array
/*
void missing_duplicate(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";
  
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
  
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
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
            cin>>temp;
            Arr[j] = temp;
        }
        
        missing_duplicate(Arr, N);
    }
     
    return 0;
}

