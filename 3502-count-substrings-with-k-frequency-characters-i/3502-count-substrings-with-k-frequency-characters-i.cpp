class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int count = 0;
        map<char, int> m;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            m[s[right]]++;
            while (m[s[right]] == k) {
                count += (s.size() - right);
                m[s[left]]--;
                left++;
            }
        }
        return count;
    }
};
