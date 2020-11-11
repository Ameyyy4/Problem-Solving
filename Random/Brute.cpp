// O(n*n) Time Complexity and O(n) Space
class Solution {
public:
    string reverseWords(string s)
    {
        string str = string(s.rbegin(), s.rend());
        // Now let us reverse the individual words separated by ' '
        if((int)str.size() == 0)
            return str;
        int i = 0;
        int s_index = 0;
        
        while(i<(int)str.size())
        {
            //Distinguish b/w the starting spaces and the space b/w the words
            //For the case of starting spaces we need to remove all spaces but b/w words we need one space
            if(str[s_index] == ' ' && str[i] != ' ')
            {
                if(s_index == 0)
                {
                    str.erase(str.begin(),str.begin()+i);
                }
                else
                {
                    if(i-s_index > 1)
                    {
                        str.erase(str.begin()+s_index+1,str.begin()+i);
                    }
                    else
                    {
                        s_index = i;
                    }
                }
                i = s_index;
            }
            else if(str[s_index]!=' ' && str[i] == ' ')
            {
                reverse(str.begin()+s_index,str.begin()+i);
                s_index = i;
            }
            i++;
        }
        // Accounting for the edge cases at the end of the string
        if(str[(int)str.size()-1] == ' ')
        {
            str.erase(str.begin()+s_index, str.end());
        }
        else
        {
            reverse(str.begin()+s_index, str.end());
        }
        return str;
    }
};
