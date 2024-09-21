class Solution {
public:
    void go(long long i, long long n, vector<int>& res) {
        if (i > n) return;
        res.push_back(i);
        for (long long j = 0; j < 10; j++) {
            go(i * 10 + j, n, res);
        }
    }
    
    vector<int> lexicalOrder(long long n) {
        vector<int> res;
        for (long long i = 1; i < 10; i++) {
            go(i, n, res);
        }
        return res;
    }
};
