class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int count=0;
        if (len==1 || len==0) return len;
        int l=0;
        int r=1;
        unordered_map<char, int> mp;
        mp[s[0]]=0;
        while(r<len){
            if(mp.find(s[r])!=mp.end()){
                count=max(count, r-l);
                while(s[l]!=s[r]){
                    mp.erase(s[l]);
                    l++;
                }
                l++;
            }
            else{
                mp[s[r]]=r;
            }
            r++;
        }
        count=max(count, r-l);
        return count;
    }
};