// TC : O(NLogN) and SC : O(1)

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> merged;
        
        if(intervals.size() == 0)
            return merged;
     
        sort(intervals.begin(), intervals.end());
        
        int s2,e2;
        int row_index = 1;
        
        vector<int> temp_interval = intervals[0];
        
        while(row_index<(int)intervals.size())
        {
        
            s2 = intervals[row_index][0];
            e2 = intervals[row_index][1];
            
            if(s2<=temp_interval[1])
            {
                temp_interval[1] = temp_interval[1]>e2?temp_interval[1]:e2;
                row_index++;
            }
            else
            {
                merged.push_back(temp_interval);
                temp_interval = intervals[row_index++];
            }
            
        }
        
        merged.push_back(temp_interval);
        return merged;
    }
};
