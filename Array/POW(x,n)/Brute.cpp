class Solution {
public:
    double myPow(double x, int n)
    {
        if(n == 0)
            return 1;
        
        double product = x;
        
        if(n == -2147483648)
        {
            n = n + 1;
            for(int i=0; i<abs(n); i++)
            {
                product *= x;
            }
            
            return 1/product;
        }
            
        for(int i=0; i<abs(n)-1; i++)
        {
            product *= x;
        }
        
        if(n<0)
            return 1/product;
        else
            return product;
    }
};
