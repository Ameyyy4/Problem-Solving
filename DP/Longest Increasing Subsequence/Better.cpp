// O(n*n) time complexity and O(n) space complexity
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums, int n)
    {
        int max = 1;
        int a[n];
        for(int i=0;i<n;i++)
        {
            a[i] = 0;
        }
        a[n-1] = 1;
        
        for(int i=n-1;i>=0;i--)
        {
            int j = i+1;
            while(j<=n-1)
            {
                if(nums[i]<nums[j])
                    break;
                j++;
            }
            if(j<=n-1)
            {
                int z = j+1;
                while(z<=n-1)
                {
                    if(nums[z]<nums[j] && nums[z]>nums[i])
                    {
                        if(a[z]>a[j])
                        {
                            j = z;
                        }
                    }
                    z++;
                }
                a[i] = a[j] + 1;
                if(max<a[i])
                    max = a[i];
            }
            else
            {
                a[i] = 1;
            }
        }
        
        return max;
    }

int main() {
    
    vector<int> nums;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        cout<<lengthOfLIS(nums, n)<<endl;
    }
    return 0;
}
