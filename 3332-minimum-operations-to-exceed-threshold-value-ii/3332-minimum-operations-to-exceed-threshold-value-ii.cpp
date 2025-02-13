class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto & it : nums) {
            pq.push(it);
        }
        int res = 0;
        while (pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top(); 
            pq.pop();
            long long z = x * 2 + y;
            pq.push(z);
            res++;
        }
        return res;
    }
};