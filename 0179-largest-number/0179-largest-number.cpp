class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstr;
        for( auto &num : nums ) {
            numstr.push_back(to_string(num));
        }
        sort( numstr.begin(), numstr.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        string res;
        for( auto &num : numstr ) {
            res += num;
        }
        if( res[0] == '0' ) {
            return "0";
        }
        return res;

    }
};