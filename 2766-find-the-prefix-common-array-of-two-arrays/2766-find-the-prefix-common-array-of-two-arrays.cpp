class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mpp;
        vector<int> res(A.size(), 0);
        int common = 0;
        for (int i = 0; i < A.size(); i++) {
            if (mpp[A[i]] > 0) {
                common++;
            }
            mpp[A[i]]++;
            if (mpp[B[i]] > 0) {
                common++;
            }
            mpp[B[i]]++;
            res[i] = common;
        }
        return res;
    }
};