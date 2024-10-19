class Solution {
public:
    string invert(string x) {
        string res = "";
        for (char c : x) 
            res+=(c=='1')?'0':'1';
        return res;
    }
    char findKthBit(int n, int k) {
        string res="0";
        for (int i = 1; i <= n; i++) {
            if (res.size() > k)
                break;
            string x = invert(res);
            reverse(x.begin(), x.end());
            res += "1" + x;
        }
        return res[k - 1];
    }
};