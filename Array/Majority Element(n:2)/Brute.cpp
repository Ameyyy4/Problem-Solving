// O(n*n) soln

public class Solution {
    public int majorityElement(vector<int>& num) {
        int count=1;
        int length=num.size();
        for (int i=0;i<length;++i) {
            for(int j=i+1;j<length;++j){
                if(num[i]==num[j])
                    ++count;
            }
            if(count>length/2)
                return num[i];
            count=1;
        }
        return -1;
    }
}
