// TC : (n*n) and SC : O(1)
// Erasing an element in vector a worst case complexity of O(N)

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        
        int s1,e1,s2,e2;
        int row_index = 0;
        
        while(row_index+1<(int)intervals.size())
        {
            
            s1 = intervals[row_index][0];
            e1 = intervals[row_index][1];
            s2 = intervals[row_index+1][0];
            e2 = intervals[row_index+1][1];
            
            if(s2<=e1 && s1<=e2)
            {
                s1 = s1>s2?s2:s1;
                e1 = e1>e2?e1:e2;
                
                intervals[row_index][0] = s1;
                intervals[row_index][1] = e1;
                intervals.erase(intervals.begin()+row_index+1);
            }
            else
            {
                row_index++;
            }
            
        }
        
        return intervals;
    }
};

