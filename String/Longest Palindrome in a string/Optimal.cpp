// O(n) Time Complexity
// My solution
class Solution {
public:
    string reverseWords(string s)
    {
        string word;
        istringstream cin(s);
        s = "";
        while (cin >> word)
        {
            s = word + " " + s;
        }
        s.pop_back();
        return s;
    }
};

// O(n) Time Complexity
class Solution {
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
        return s;
    }
};
