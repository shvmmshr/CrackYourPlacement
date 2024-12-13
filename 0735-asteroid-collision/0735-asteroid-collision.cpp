class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int i : asteroids) {
            bool destroyed = false;
            while (!s.empty() && i < 0 && s.top() > 0) {
                if (abs(i) > abs(s.top())) {
                    s.pop();
                } else if (abs(i) == abs(s.top())) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                s.push(i);
            }
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
