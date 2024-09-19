class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        // Base case: If the expression contains only a number (no operators), return it
        if (all_of(expression.begin(), expression.end(), ::isdigit)) {
            result.push_back(stoi(expression));
            return result;
        }

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            // If we encounter an operator, split the expression into two parts
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Compute all possible combinations of left and right parts
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') result.push_back(l + r);
                        else if (c == '-') result.push_back(l - r);
                        else result.push_back(l * r);
                    }
                }
            }
        }

        return result;
    }
};