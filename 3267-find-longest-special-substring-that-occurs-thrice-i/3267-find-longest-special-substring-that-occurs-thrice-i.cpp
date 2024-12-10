class Solution {
public:
    int maximumLength(string s) {
        map<string, int> mp;
        string temp = "";
        temp += s[0];
        mp[temp]++;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                temp += s[i];
            } else {
                temp = s[i];
            }
            for (int j = 0; j < temp.size(); j++) {
                string local = temp.substr(0, j + 1);
                mp[local]++;
            }
        }
        int ans = 0;
        for (auto a : mp) {
            if (a.second >= 3) {
                int size = a.first.size();
                ans = max(ans, size);
            }
        }
        return ans == 0 ? -1 : ans;

    }
};