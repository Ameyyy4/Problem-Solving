// TC : O(nlogn) SC : O(n)
#include <iostream>
#include <vector>
using namespace std;
int count_inv(vector<int> &vec, int l, int m, int e, int &count)
{
    vector<int> arr1;
    vector<int> arr2;
    for(int i=l;i<=m;i++)
    {
        arr1.push_back(vec[i]);
    }
    for(int i=m+1;i<=e;i++)
    {
        arr2.push_back(vec[i]);
    }
    
    int index1 = l;
    int index2 = m+1;
    int index = l;
    
    while(index1 != m+1 && index2 != e+1)
    {
        if(arr1[index1-l]>arr2[index2-m-1])
        {
            vec[index] = arr2[index2-m-1];
            count += m-index1+1;
            index2++;
            index++;
        }
        if(arr1[index1-l]<arr2[index2-m-1])
        {
            vec[index] = arr1[index1-l];
            index1++;
            index++;
        }
    }
    
    if(index1 == m+1)
    {
        for(int i = index;i<=e;i++)
        {
            vec[i] = arr2[index2-m-1];
            index2++;
        }
    }
    else if(index2 == e+1)
    {
        for(int i = index;i<=e;i++)
        {
            vec[i] = arr1[index1-l];
            index1++;
        }
    }
    return count;
}
void merge_sort(vector<int> &vec,int left, int right, int &count)
{
    if(left >= right)
        return ;
    merge_sort(vec, left, (left+right)/2,count);
    merge_sort(vec, (left+right)/2 + 1, right,count);

    count_inv(vec,left,(left+right)/2,right,count);
    return;
}
int main()
{
    int testcases;
    cin>>testcases;
    int count;
    for(int i=0;i<testcases;i++)
    {
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        count = 0;
        merge_sort(vec,0,n-1,count);
        cout<<count<<endl;
    }
    return 0;
}
