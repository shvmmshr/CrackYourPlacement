class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        vector<int> mp(26,INT_MAX);
        for(string word:words){
            vector<int> temp(26,0);
            for(char c:word){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                mp[i]=min(mp[i],temp[i]);
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<mp[i];j++){
                res.push_back(string(1,'a'+i));
            }
        }
        return res;
    }
};