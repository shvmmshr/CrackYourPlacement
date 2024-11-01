class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            if (j - i >= 2) {
                ans += s[i];
                ans += s[i];
            } else {
                ans += s[i];
            }
            i = j - 1;
        }
        return ans;
    }
};