class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;  
        while (ss >> word) {
            words.push_back(word);
        }
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            int nextIndex = (i + 1) % n;
            if (words[i].back() != words[nextIndex].front()) {
                return false;
            }
        }
        
        return true;
    }
};
