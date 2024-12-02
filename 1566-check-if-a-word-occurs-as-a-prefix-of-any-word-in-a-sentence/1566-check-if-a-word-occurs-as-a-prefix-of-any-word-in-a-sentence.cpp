class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1;
        int pos = 0;
        int n = sentence.size();
        int prefixLength = searchWord.size();
        while (pos < n) {
            int end = pos;
            while (end < n && sentence[end] != ' ') end++;
            if (end - pos >= prefixLength && sentence.substr(pos, prefixLength) == searchWord) {
                return wordIndex;
            }
            pos = end + 1;
            wordIndex++;
        }
        return -1;
    }
};
