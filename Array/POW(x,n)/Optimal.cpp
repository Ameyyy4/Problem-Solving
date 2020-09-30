// Time Complexity of O(n) and space complexity of O(1)
// There is a special case to be boted when n = -2147483648
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n)
{
    if(n == 0)
        return 1;
    
    long long int m = n;
    //or We can use unsigned int m = abs(n)
    //cout<<m<<endl;
    if(m<0)
        m *= -1;
    //cout<<m<<endl;
    while(m>0)
    {
        if(m%2 == 0)
        {
            x = x*x;
            m = m/2;
        }
        else
        {
            m -= 1;
            x = x * myPow(x,m);
            if(n<0)
                return 1/x;
            else
                return x;
        }
    }
    return x;
}
// bit operations
double myPow(double x, int n) {
    if(n==0) return 1;
    long long int m;
    if(n<0) {
        m = -1 * n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    double x;
    
    cin>>x;
    cin>>n;
    
    cout<<myPow(x,n);
    return 0;
}
