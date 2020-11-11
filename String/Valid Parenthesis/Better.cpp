// O(n) TC as well as SC
class Solution {
public:
    bool isValid(string s)
    {
        // Can easily do this question using stack approach
        vector<char> vec;
        
        // We always have unmatched brackets in vector
        // Whenever we find any match we simple pop the last element and thus remain with unmatched elements in vector
        // If any of the closing bracket comes then we see the last bracket and compare
        // Let us take the input step by step and compare at each step
        
        int n = s.size();
        int i = 0;
        
        while(i<n)
        {
            // initial check of empty
            if(!vec.empty())
            {
                // Either a opening or a closing bracket
                if(s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    switch(s[i])
                    {
                        case ')' :
                            if(vec.back() == '(')
                                vec.pop_back();
                            else
                                return false;
                            break;
                        case ']' :
                            if(vec.back() == '[')
                                vec.pop_back();
                            else
                                return false;
                            break;
                        case '}' :
                            if(vec.back() == '{')
                                vec.pop_back();
                            else
                                return false;
                            break;
                    }
                }
                else
                {
                    vec.push_back(s[i]);
                }
            }
            else
            {
                // If closing then return false
                if(s[i] == ')' || s[i] == ']' || s[i] == '}')
                    return false;
                else
                    vec.push_back(s[i]);
            }
            
            i++;     // Incrementing the index
        }
        
        if((int)vec.size()>0)       // Finally we should a get a empty vector for matched case
            return false;
        return true;
    }
};

// A shorter and cleaner code
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};
