class Solution {
public:
    string toBinary(int num) {
        return bitset<32>(num).to_string().substr(bitset<32>(num).to_string().find('1'));
    } 
    string maxGoodBinary(vector<int>& nums) {
        vector<string> binaries;
        for (int num : nums) {
            binaries.push_back(toBinary(num));
        }
        sort(binaries.begin(), binaries.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        string result = "";
        for (string &bin : binaries) {
            result += bin;
        }
        return result;
    }
    int maxGoodNumber(vector<int>& nums) {
        string binaryString = maxGoodBinary(nums);
        long long maxNumber = stoll(binaryString, nullptr, 2);
        return maxNumber;
    }
};
