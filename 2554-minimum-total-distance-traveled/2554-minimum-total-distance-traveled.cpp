class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m = robot.size();
        int n = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<long long> dp(m + 1, LLONG_MAX);
        dp[0] = 0;

        for (const auto& f : factory) {
            int f_pos = f[0];
            int f_limit = f[1];

            vector<long long> next_dp = dp;

            for (int i = m; i > 0; --i) {
                long long sum_dist = 0;

                for (int k = 1; k <= f_limit && i - k >= 0; ++k) {
                    sum_dist += abs(robot[i - k] - f_pos);
                    if (dp[i - k] != LLONG_MAX) {
                        next_dp[i] = min(next_dp[i], dp[i - k] + sum_dist);
                    }
                }
            }

            dp = move(next_dp);
        }

        return dp[m];
    }
};
