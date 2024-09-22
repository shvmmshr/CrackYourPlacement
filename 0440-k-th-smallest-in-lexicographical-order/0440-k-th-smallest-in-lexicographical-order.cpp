class Solution {
public:
    long long count(long long cur, long long n) {
        long long res = 0;
        long long nei = cur + 1;
        while (cur <= n) {
            res += min(nei, n + 1) - cur;
            cur *= 10;
            nei *= 10;
        }
        return res;
    }
    
    int findKthNumber(int n, int k) {
        long long cur = 1;
        int i = 1;
        while (i < k) {
            long long steps = count(cur, n);
            if (i + steps <= k) {
                cur = cur + 1;
                i += steps;
            } else {
                cur *= 10;
                i = i + 1;
            }
        }
        return cur;
    }
};
