class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        int size = 0;
        
        // Skip trailing spaces
        while (len >= 0 && s[len] == ' ') {
            len--;
        }
        
        // Count the length of the last word
        while (len >= 0 && s[len] != ' ') {
            size++;
            len--;
        }
        
        return size;
    }
};
