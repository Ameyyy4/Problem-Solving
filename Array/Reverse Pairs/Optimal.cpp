// O(nlogn) solution
class Solution {
 public:
     void merge(vector<int>& nums, int l, int m, int r, int& count)
     {
         vector<int> num1(m-l+1);
         vector<int> num2(r-m);
         
         for(int i=l;i<=m;i++)
         {
             num1[i-l] = nums[i];
         }
         for(int i=m+1;i<=r;i++)
         {
             num2[i-m-1] = nums[i];
         }
         
         int index1 = 0;
         int index2 = 0;
         while(index1!=(m-l+1))
         {
             while(index2!=(r-m) && (long)num1[index1]>(long)2*num2[index2] )
             {
                 index2++;
             }
             count += index2;
             index1++;
         }
         
         int index = l;
         index1 = 0;
         index2 = 0;
         while(index1!=(m-l+1) && index2!=(r-m))
         {
             if(num1[index1]>=num2[index2])
             {
                 nums[index] = num2[index2];
                 index++;
                 index2++;
             }
             else
             {
                 nums[index] = num1[index1];
                 index++;
                 index1++;
             }
         }
         if(index1 == m-l+1)
         {
             for(int i = index;i<=r;i++)
             {
                 nums[i] = num2[index2];
                 index2++;
             }
         }
         else
         {
             for(int i = index;i<=r;i++)
             {
                 nums[i] = num1[index1];
                 index1++;
             }
         }
         return ;
     }
     void mergesort(vector<int>& nums, int l, int r, int& count)
     {
         if(l>=r)
             return;
         mergesort(nums,l,(l+r)/2,count);
         mergesort(nums,(l+r)/2+1,r,count);
         merge(nums,l,(l+r)/2,r,count);
         return;
     }
     int reversePairs(vector<int>& nums)
     {
         int count = 0;
         int n = (int)nums.size();
         mergesort(nums, 0, n-1, count);
         return count;
     }
 };
