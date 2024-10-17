class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        if (n == 1) return num;
        vector<int> maxIndex(n);
        maxIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (str[i] > str[maxIndex[i + 1]]) {
                maxIndex[i] = i;
            } else {
                maxIndex[i] = maxIndex[i + 1];
            }
        }
        for (int i = 0; i < n; i++) {
            if (str[i] < str[maxIndex[i]]) {
                swap(str[i], str[maxIndex[i]]);
                return stoi(str);
            }
        }
        return num;
    }
};
