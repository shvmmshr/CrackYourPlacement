class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;
        map<char, int> mp;
        for (auto &it : s) {
            mp[it]++;
        }
        for (auto it : mp) {
            pq.emplace(it.first, it.second);
        }
        string ans;
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            char ch = it.first;
            int cnt = it.second;
            int use = min(cnt, repeatLimit);
            ans.append(use, ch);
            cnt -= use;
            if (cnt > 0) { 
                if (!pq.empty()) {
                    auto sc = pq.top(); pq.pop();
                    char nextChar = sc.first;
                    int nextCnt = sc.second;
                    ans.push_back(nextChar);
                    nextCnt--;
                    if (nextCnt > 0) {
                        pq.emplace(nextChar, nextCnt);
                    }
                } else {
                    break;
                }
                pq.emplace(ch, cnt);
            }
        }
        return ans;
    }
};