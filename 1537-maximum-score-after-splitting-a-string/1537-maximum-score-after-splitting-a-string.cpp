class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char ch : s) {
            if (ch == '1') {
                totalOnes++;
            }
        }
        int maxScore = 0;
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones++;
            }  
            int currentScore = zeros + (totalOnes - ones);
            
            if (currentScore > maxScore) {
                maxScore = currentScore;
            }
        }
        return maxScore;
    }
};