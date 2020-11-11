// O(n^3) TC as we copy in inner most loop

class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = (int)s.size();
        int n = len;
        int index;
        while(len)
        {
            index = 0;
            while(index+len-1<n)
            {
                // for each string of length len check if its palindromic or not
                // any string ranges from index to index + len -1
                //cout<<index<<" "<<index+len-1<<endl;
                string str1 = s.substr(index, len);// stores the substring
                string str2 = string(str1.rbegin(),str1.rend()); // Stores the reverse of str1
                //cout<<str1<<" "<<str2<<endl;
                if(str1 == str2)
                    return str1;
                index++;
            }
            // Decrement the length of string
            len--;
        }
        return s;
    }
};
