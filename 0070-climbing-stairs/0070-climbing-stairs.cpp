class Solution {
public:
    int climbStairs(int n) {
        int one=1;
        int two=1;
        int res=0;
        for(int i=0;i<n-1;i++){
            int temp;
            temp=one;
            one=one+two;
            two=temp;
        }
        return one;
    }
};