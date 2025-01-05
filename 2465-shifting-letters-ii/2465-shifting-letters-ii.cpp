class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> differ(n+1, 0);
        for(auto& shift: shifts)
        {
           if(shift[2] == 0) {
            differ[shift[0]] += -1;
            if(shift[1]+1) differ[shift[1]+1] += 1;
           }
           else{
            differ[shift[0]] += 1;
            if(shift[1]+1) differ[shift[1]+1] += -1;
           }
        } 
        int prefix_sum = 0;
        for(int i=0;i<n;i++)
        {
            prefix_sum = (prefix_sum + differ[i]) %26;
            if(prefix_sum < 0) prefix_sum += 26;
            s[i] = 'a' + (s[i]-'a'+prefix_sum)%26;
        }
       return s;
    }
};