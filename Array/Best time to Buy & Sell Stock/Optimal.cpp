// O(n) approach
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0)
            return 0;
        int max = 0;
        int n = (int)prices.size();
        int min = prices[0];
        
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prices[i-1])
            {
                if(prices[i]-min>max)
                    max = prices[i]-min;
            }
            else
            {
                if(prices[i]<min)
                    min = prices[i];
            }
        }
        
        return max;
    }
};
