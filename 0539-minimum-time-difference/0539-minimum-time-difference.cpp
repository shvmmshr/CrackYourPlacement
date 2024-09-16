class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
        }
        sort(time.begin(), time.end());
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            ans = min(ans, time[i] - time[i - 1]);
        }
        ans = min(ans, time[0] + 1440 - time[n - 1]);
        return ans;
    }
};