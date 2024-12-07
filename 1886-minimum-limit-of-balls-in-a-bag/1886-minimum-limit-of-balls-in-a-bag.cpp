class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int mx = 0;
        for (auto& n : nums) {
            mx = max(mx, n);
        }

        int l = 1, r = mx, mid, ops, res;
        while (l <= r) {
            ops = 0;
            mid = (r - l) / 2 + l;
            for (auto& n : nums) {
                ops += (n % mid == 0) ? (n / mid - 1) : (n / mid);
            }

            if (ops > k) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};
