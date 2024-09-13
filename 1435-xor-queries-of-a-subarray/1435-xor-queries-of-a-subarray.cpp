class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }

        vector<int> res;

        for (const auto& q : queries) {
            int L = q[0], R = q[1];
            res.push_back(prefixXor[R + 1] ^ prefixXor[L]);
        }

        return res;
    }
};
