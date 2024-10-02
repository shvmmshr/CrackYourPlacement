class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char,int> freq;
        for(char c: words[0]){
            freq[c]++;
        }
        for(int i=1;i<words.size();i++){
            map<char,int> freq1;
            for(char c:words[i]) {
                freq1[c]++;
            }
            for(auto it:freq){
                freq[it.first]=min(it.second,freq1[it.first]);
                if(it.second==0){
                    freq.erase(it.first);
                }
            }
            
        }
        vector<string> res;
        for(auto it:freq){
            for(int i=0;i<it.second;i++){
                res.push_back(string(1,it.first));
            }
        }
        return res;
    }
};