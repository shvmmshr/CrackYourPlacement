class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left_box(n + 1, 0), right_box(n + 1, 0), ans(n);
        int lball = 0, rball = 0;
        for (int i = 0; i < n; ++i) {
            left_box[i + 1] = left_box[i] + lball;
            if (boxes[i] == '1') lball++;
        }
        for (int i = n - 1; i >= 0; --i) {
            right_box[i] = right_box[i + 1] + rball;
            if (boxes[i] == '1') rball++;
        }
        for (int i = 1; i <= n; ++i) {
            ans[i - 1] = left_box[i] + right_box[i - 1];
        }
        return ans;
    }
};