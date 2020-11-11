// O(n*n) approach
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max = 0;
        int n = prices.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if(prices[j]-prices[i] > max)
                    max = prices[j]-prices[i];
        }
        return max;
    }
};
