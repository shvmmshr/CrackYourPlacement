class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1, s2;
        istringstream iss1(sentence1), iss2(sentence2);
        string word;
        while (iss1 >> word) s1.push_back(word);
        while (iss2 >> word) s2.push_back(word);
        if (s1.size() < s2.size()) swap(s1, s2);
        int i = 0;
        while (i < s2.size() && s1[i] == s2[i]) i++;
        while (i < s2.size() && s1[s1.size() - s2.size() + i] == s2[i]) i++;
        return i == s2.size();
    }
};