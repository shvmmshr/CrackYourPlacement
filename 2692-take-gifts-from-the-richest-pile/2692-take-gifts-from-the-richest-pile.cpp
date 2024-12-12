class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        long long sum = 0;
        priority_queue<int> pq;
        for (auto i : gifts) {
            pq.push(i);
        }
        while (k--) {
            int top = pq.top();
            pq.pop();
            int newGift = floor(sqrt(top));
            pq.push(newGift);
        }
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};