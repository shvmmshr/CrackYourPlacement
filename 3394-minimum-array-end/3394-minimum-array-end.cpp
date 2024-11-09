#include <bitset>
class Solution {
public:
    long long minEnd(int n, int x) {
        std::bitset<64> X(x), N(n - 1), result(0);

        int j = 0;
        for (int i = 0; i < 64; i++) {
            if (X[i]) {
                result[i] = 1;
            } else {
                result[i] = N[j];
                j++;
            }
        }

        return result.to_ullong();
    }
};