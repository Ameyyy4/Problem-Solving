// O(n) TC and O(1) SC
// calculate the amount of water over each bar by having the minimum water level
class Solution {
public:
    int trap(vector<int>& height)
    {
        int l = 0, r = (int)height.size()-1, water = 0, level = 0;
        while(l<r)
        {
            int min_height = height[l]>height[r]?height[r--]:height[l++];
            int level = max(level,min_height);
            water += level-min_height;
        }
        return water;
    }
};


