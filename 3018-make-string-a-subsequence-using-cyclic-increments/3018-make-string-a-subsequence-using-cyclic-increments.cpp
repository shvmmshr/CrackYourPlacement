class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l1 = str1.size(), l2 = str2.size();
        if (l1 < l2) return false;
        int it1 = 0, it2 = 0;
        char next;
        while (it1 < l1 && it2 < l2) {
            next = (str1[it1] == 'z') ? 'a' : str1[it1] + 1;
            if (str1[it1] == str2[it2] || next == str2[it2]) {
                it2++;
            }
            it1++;
        }
        return it2 == l2;
    }
};