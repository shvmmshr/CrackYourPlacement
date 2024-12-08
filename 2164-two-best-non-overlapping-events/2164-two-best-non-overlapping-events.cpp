class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> maxValue(n, 0);
        maxValue[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            maxValue[i] = max(maxValue[i + 1], events[i][2]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int curr = events[i][2];
            result = max(result, curr);

            int l = i + 1, r = n - 1, next = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (events[mid][0] > events[i][1]) {
                    next = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (next != -1) {
                result = max(result, curr + maxValue[next]);
            }
        }
        return result;
    }
};