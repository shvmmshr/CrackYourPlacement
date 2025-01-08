class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int l1=words[i].size();
                int l2=words[j].size();
                if(l1>l2) continue;
                string pre = words[j].substr(0, l1);
                string suf = words[j].substr(l2 - l1);
                if(pre==words[i] && suf==words[i]) count++;
            }
        }
        return count;
    }
};