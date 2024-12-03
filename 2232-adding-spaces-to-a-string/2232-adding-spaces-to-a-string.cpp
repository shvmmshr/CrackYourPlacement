class Solution {
public:
    string addSpaces(string s, vector<int>& a) {
        string ans = "";
        int ind = 0;
        for(int i=0;i<s.size();i++){
            if(ind<a.size()&&i==a[ind]){
                ans+=' ';
                ind++;
            }
            ans+=s[i];
        }
        return ans;
    }
};