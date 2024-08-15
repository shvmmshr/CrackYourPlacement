class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        digits[len-1]++;
        for(int i=len-1;i>=1;i--){
            if(digits[i]/10>0){
                digits[i]=0;
                digits[i-1]++;
            }
        }
        if(digits[0]/10>0){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};