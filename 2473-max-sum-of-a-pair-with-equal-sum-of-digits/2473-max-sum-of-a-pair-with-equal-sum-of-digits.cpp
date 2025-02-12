#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        map<int, priority_queue<int>> mpp;
        for (int num : nums) {
            int sumDigits = findSum(num);
            mpp[sumDigits].push(num);
        }
        for (auto& it : mpp) {
            if (it.second.size() < 2) continue;
            int n1 = it.second.top();
            it.second.pop();
            int n2 = it.second.top();
            res = max(res, n1 + n2);
        }
        return res;
    }
};

