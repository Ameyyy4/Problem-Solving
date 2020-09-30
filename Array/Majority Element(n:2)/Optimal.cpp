// Moore's Voting Algo
// TC : O(n)
// SC : O(1)
class Solution {
public:
    int majorityElement(vector<int>& a)
    {
        int n = a.size();
        int count = 0;
        int number;
        
        for(int i=0; i<n; i++)
        {
            if(count == 0)
                number = a[i];
            if(number == a[i])
                count++;
            if(number != a[i])
                count--;
        }
        
        return number;
    }
};
// Bit Manipulation
// The bits in the majority are just the majority bits of all no.s
// TC : O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
};


