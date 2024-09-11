class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res= start ^ goal;
        int count=0;
        while(res){
            if(res&1) count++;
            res=res>>1;
        }
        return count;
    }
};