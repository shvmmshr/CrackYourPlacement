class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find("*");
        string b = p.substr(0, x);
        string e = p.substr(x + 1);
        int i = s.find(b);
        int j = s.rfind(e);
        return i != -1 && j != -1 && i + b.size() <= j;
    }
};