class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(word1.size(), word2.size());
        string str = "";
        for (int i = 0; i < n; i++) {
            str += word1[i];
            str += word2[i];
        }
        if(word1.size()>n) str+=word1.substr(n);
        if(word2.size()>n) str+=word2.substr(n);
        return str;
    }
};