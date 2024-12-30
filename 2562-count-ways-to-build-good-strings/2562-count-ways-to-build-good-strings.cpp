class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> memo;

    int countWays(int length, int low, int high, int zero, int one) {
        if (length > high) return 0;
        if (memo[length] != -1) return memo[length];
        int result = (length >= low) ? 1 : 0;
        result = (result + countWays(length + zero, low, high, zero, one)) % mod;
        result = (result + countWays(length + one, low, high, zero, one)) % mod;
        return memo[length] = result;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memo.assign(high + 1, -1);
        return countWays(0, low, high, zero, one);
    }
};