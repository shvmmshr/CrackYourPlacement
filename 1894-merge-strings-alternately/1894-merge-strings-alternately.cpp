class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(word1.size(), word2.size());
        string str = "";
        for (int i = 0; i < n; i++) {
            str += word1[i];
            str += word2[i];
            if (i == n-1 && i < word2.size())
                str+=word2.substr(i+1,word2.size()-i-1);
            if (i == n-1 && i < word1.size())
                str+=word1.substr(i+1,word1.size()-i-1);
        }
        return str;
    }
};