class Solution {
public:
    int countPalindromicSubsequence(string s) {
	map<char, vector<int>> mp;

	for (int i = 0; i < s.size(); i++) {
		mp[s[i]].push_back(i);
	}
	int res = 0;
	for (auto it : mp) {
		vector<int> index = it.second;
		int l_index = index[0];
		int r_index = index[index.size() - 1];
		if (r_index - l_index > 1) {  
			unordered_set<int> unique;
			for (int i = l_index + 1; i < r_index; i++) {
				unique.insert(s[i]);
			}
			res = res + unique.size();
		}
	}
	return res;
}
};