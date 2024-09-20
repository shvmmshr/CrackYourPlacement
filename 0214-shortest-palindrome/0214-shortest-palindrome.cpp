class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + "#" + rev;
        vector<int> p(l.size(), 0);
        for( int i = 1; i < l.size(); i++ ) {
            int j = p[i-1];
            while( j > 0 && l[i] != l[j] ) {
                j = p[j-1];
            }
            p[i] = j + (l[i] == l[j]);
        }
        return rev.substr(0, s.size() - p[l.size()-1]) + s;
    }
};