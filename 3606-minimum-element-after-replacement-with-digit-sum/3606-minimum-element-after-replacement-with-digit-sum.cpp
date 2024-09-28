class Solution {
public:
    int sumofdigits(int n){
        int res=0;
        while(n>0){
            res+=n%10;
            n/=10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int res=INT_MAX;
        for(auto &c:nums){
            c=sumofdigits(c);
            res=min(res,c);
        }
        return res;
    }
};