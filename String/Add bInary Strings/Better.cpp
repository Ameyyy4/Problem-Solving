// O(n) TC and O(n) SC
class Solution {
public:
    string addBinary(string a, string b)
    {
        // Define a new string c which stores the result of the a+b;
        string c;
        // Reverse the String to get the LSB at initial Index
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        // Go inside the Loop and add the value at particular index and carry to get value at c index
        int i = 0;
        int carry = 0;
        int val;              // Stores the value of particular index addition
        while(i<(int)a.size() || i<(int)b.size())
        {
            val = carry;        // Set the value to carry
            
            if(i<(int)a.size()) // check if we are in the index of string a and b and then add it
                val += a[i] - '0';
            if(i<(int)b.size())
                val += b[i] - '0';
            
            //cout<<val<<" ";
            if(val%2 == 0)
                c.push_back('0'); // if(val == even) then replace with 0 and if val == odd then with 1
            else
                c.push_back('1');
            
            if(val < 2)           // check the val and appropriately assign carry
                carry = 0;
            else
                carry = 1;
            
            i++;               // Increment in index
        }
        
        if(carry)
            c.push_back('1');
        
        reverse(c.begin(),c.end());
        
        return c;
            
    }
};



class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};

