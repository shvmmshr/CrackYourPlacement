class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(bannedWords.begin(), bannedWords.end());
        int c=0;
        for( string& word : message ) {
            if( banned.count(word)) {
                c++;
            }
        }
        if (c >= 2) {
            return true;
        }
        return false;
    }
};