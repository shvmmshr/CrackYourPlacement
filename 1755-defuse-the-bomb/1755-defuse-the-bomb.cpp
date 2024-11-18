class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        for (int i = 0; i < code.size(); i++) {
            int sum = 0;
            if (k == 0) {
                res.push_back(0);
            }
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j + code.size()) % code.size()];
                }
                res.push_back(sum);
            }
            if (k < 0) {
                for (int j = 1; j <= abs(k); j++) {
                    sum += code[(i - j + code.size()) % code.size()];
                }
                res.push_back(sum);
            }
        }
        return res;
    }
};