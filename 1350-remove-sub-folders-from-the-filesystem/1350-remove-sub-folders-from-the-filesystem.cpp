class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        string prev = "";
        for (const string& f : folder) {
            if (prev.empty() || f.compare(0, prev.size(), prev) != 0 || f[prev.size()] != '/') {
            result.push_back(f);
            prev = f;
            }
        }
        return result;
    }
};