class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len=nums.size();
        vector<int> res(len);
        int pos=0,neg=1;
        for(int num : nums){
            if(num>0){
                res[pos]=num;
                pos=pos+2;
            }
            else{
                res[neg]=num;
                neg=neg+2;
            }
        }
        return res;

    }
};