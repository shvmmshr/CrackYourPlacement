class Solution {
public:
    bool parseBoolExpr(string expression) {
        return eval(expression, 0, expression.size() - 1);
    }
    bool eval(const string& expr, int start, int end) {
        if (start == end) {
            return expr[start] == 't';
        }
        char op = expr[start];
        if (op == '!') {
            return !eval(expr, start + 2, end - 1);
        }
        vector<bool> results;
        int i = start + 2;
        int balance = 0;
        int subStart = i;
        while (i <= end) {
            if (expr[i] == '(') {
                balance++;
            } else if (expr[i] == ')') {
                balance--;
            }
            if ((expr[i] == ',' && balance == 0) ||
                (expr[i] == ')' && balance == -1)) {
                results.push_back(eval(expr, subStart, i - 1));
                subStart = i + 1;
            }
            i++;
        }
        if (op == '&') {
            for (bool result : results) {
                if (!result)
                    return false;
            }
            return true;
        } else if (op == '|') {
            for (bool result : results) {
                if (result)
                    return true;
            }
            return false;
        }
        return false;
    }
};
