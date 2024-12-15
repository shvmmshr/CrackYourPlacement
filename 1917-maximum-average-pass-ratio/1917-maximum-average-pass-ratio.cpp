class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto &x: classes) {
            double ori = 1.0 * x[0] / x[1];
            double nxt = 1.0 * (x[0] + 1) / (x[1] + 1);
            double changeRatio = nxt - ori;
            pq.push({changeRatio, {x[0], x[1]}});
        }
        while (extraStudents--) {
            auto [ratio, info] = pq.top();
            pq.pop();
            auto [pass, total] = info;
            pass += 1, total += 1;
            double ori = 1.0 * pass / total;
            double nxt = 1.0 * (pass + 1) / (total + 1);
            double changeRatio = nxt - ori;
            pq.push({changeRatio, {pass, total}});
        }
        double result = 0;
        while (!pq.empty()) {
            auto [ratio, info] = pq.top();
            pq.pop();
            auto [pass, total] = info;
            result += 1.0 * pass / total;
        }
        int n = classes.size();
        return result / n;
    }
};