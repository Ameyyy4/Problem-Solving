// My Solution
// Derived a pattern and then generalized to get the result
// TC : p = m>n?n:m; O(p)
// SC : O(1)
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        double d;
        double f;
        int path = 1;
        
        if(m == 1 || n == 1)
            return 1;
        else
        {
            for(int i=1; i<=m-1; i++)
            {
                d = ((double)(i+1)/(double)i) - (double)1;
                f = (double)1 + (double)(n-1)*d;
                if(ceil(path*f)-path*f>path*f-floor(path*f))
                {
                    path = floor(path*f);
                }
                else
                {
                    path = ceil(path*f);
                }
                //cout<<path<<endl;
            }
        }
        return path;
    }
    
};

// Combination Soln
// O(m) or O(n) if n is greater or m is greater respectively
class Solution {
public:
    int choose_fun(int n, int r)
    {
        if(r == 0)
            return 1;
        long long t = (long long)n * choose_fun(n-1,r-1);
        return t/r;
    }
    int uniquePaths(int m, int n)
    {
        if(m == 1 || n == 1)
            return 1;
        return choose_fun(m+n-2,(m>n?n:m)-1);
    }
    
};

