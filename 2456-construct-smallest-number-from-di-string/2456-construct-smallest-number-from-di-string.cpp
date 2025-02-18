class Solution {
public:
    string smallestNumber(string pattern) {
        int s[10] = {'1'}, top = 0, j = 0;
        for (int i = 0; i < pattern.length(); i++){
            if (pattern[i] == 'I')
                while (top >= 0) pattern[j++] = s[top--];
            s[++top] = i + 1 + '1';
        }
        while (top > 0)
            pattern[j++] = s[top--];
        if (top == 0) pattern.push_back(s[top]);
        return pattern;
    }
};