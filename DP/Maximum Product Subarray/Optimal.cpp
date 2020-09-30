// Time Complexity of O(n) and space complexity of O(1)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> A)
    {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = nums[0];
        for(int i=1,imax=p,imin=p;i<nums.size();i++) {
            cout<<imax<<" "<<imin<<" "<<p<<endl;
            if(nums[i]<0) swap(imax,imin);
            imax = max(nums[i],imax*nums[i]);
            imin = min(nums[i],imin*nums[i]);
            p = max(p,imax);
        }
        return p;
    }
};

//O(n) divide and conquer
int maxProduct(vector<int>& nums) {
    int maxl, maxr, minl, minr, p;
    return dac(0,nums.size()-1,maxl,maxr,minl,minr,p,nums);
}
int dac(int l, int r, int& maxl, int& maxr, int& minl, int& minr, int& p,vector<int>& nums) {
    if(l==r) return maxl=maxr=minl=minr=p=nums[l];
    int mid = (l+r)/2, lmaxl,lmaxr,lminl,lminr,lp,rmaxl,rmaxr,rminl,rminr,rp;
    int mp = max(dac(l,mid,lmaxl,lmaxr,lminl,lminr,lp,nums),dac(mid+1,r,rmaxl,rmaxr,rminl,rminr,rp,nums));
    maxl = max(lmaxl,max(lp*rmaxl,lp*rminl));
    maxr = max(rmaxr,max(rp*lmaxr,rp*lminr));
    minl = min(lminl,min(lp*rminl,lp*rmaxl));
    minr = min(rminr, min(rp*lminr,rp*lmaxr));
    p = lp*rp;
    return max(mp,max(lmaxr*rmaxl,lminr*rminl));
}
