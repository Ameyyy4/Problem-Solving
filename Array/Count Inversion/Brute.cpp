// TC : O(n*n) SC : O(n) - For a single Test Case
// SC is due to the input size
#include <iostream>
#include <vector>
using namespace std;
int count_inv(vector<int> &vec, int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(vec[i]>vec[j])
                count++;
        }
    }
    return count;
}
int main()
{
    int testcases;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        cout<<count_inv(vec,n)<<endl;
    }
    return 0;
}
