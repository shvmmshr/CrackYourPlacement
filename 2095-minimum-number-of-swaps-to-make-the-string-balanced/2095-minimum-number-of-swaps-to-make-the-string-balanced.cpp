class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0, maxImbalance = 0;
        for (char c : s) {
            if (c == '[') {
                imbalance++;
            } else {
                imbalance--;
            }
            maxImbalance = min(maxImbalance, imbalance);
        }
        return (-maxImbalance + 1) / 2;
    }
};
