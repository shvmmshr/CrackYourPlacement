class Solution {
public:
    int getLucky(string s, int k) {
        long long sum = 0;
        for (char c : s) {
            int num = c - 'a' + 1;
            sum += num / 10 + num % 10;
        }
        while (--k > 0) {
            long long newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }
        return sum;
    }
};
