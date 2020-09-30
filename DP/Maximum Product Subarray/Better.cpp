// O(nlogn) Naive divide and conquer
int maxProduct(vector<int>& nums) {
    return dac(0,nums.size()-1,nums);
}
int dac(int l, int r, vector<int>& nums) {
    if(l==r) return nums[l];
    int mid = (l+r)/2, minL=INT_MAX, minR=INT_MAX, maxL=INT_MIN, maxR=INT_MIN, temp =1;
    for(int i=mid;i>=l;i--) {
        minL = min(minL,temp*=nums[i]);
        maxL = max(maxL,temp);
    }
    temp = 1;
    for(int i=mid+1;i<=r;i++) {
        minR = min(minR,temp*=nums[i]);
        maxR = max(maxR,temp);
    }
    return max(max(dac(l,mid,nums),dac(mid+1,r,nums)),max(minR*minL,maxR*maxL));
}

// 
