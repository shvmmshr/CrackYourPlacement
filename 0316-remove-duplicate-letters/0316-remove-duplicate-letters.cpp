class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int>freq(26,0), visited(26,0);
        for(auto ch:s)freq[ch-'a']++;

        string ans;
        int n = s.length();
        for(int i=0;i<n;i++){
               freq[s[i]-'a']--;
               if(!visited[s[i]-'a']){ 
                while(ans.size() and ans.back()>s[i] and freq[ans.back()-'a']>0) {
                    visited[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                visited[s[i]-'a'] = 1;
                }
        }
        return ans;
    }
};