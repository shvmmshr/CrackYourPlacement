class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> arrivals;
        for (int i = 0; i < n; i++) arrivals.push_back({times[i][0], i});
        sort(arrivals.begin(), arrivals.end());
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++) availableChairs.push(i); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingTimes;
        vector<int> chairAssigned(n, -1);
        for (int i = 0; i < n; i++) {
            int arrival = arrivals[i].first;
            int idx = arrivals[i].second;
            while (!leavingTimes.empty() && leavingTimes.top().first <= arrival) {
                availableChairs.push(chairAssigned[leavingTimes.top().second]);
                leavingTimes.pop();
            }
            int chair = availableChairs.top();
            availableChairs.pop();
            chairAssigned[idx] = chair;
            if (idx == targetFriend) {
                return chair;
            }
            leavingTimes.push({times[idx][1], idx});
        }
        return -1;
    }
};
