class Solution {
public:
    int mySqrt(int x) {
        long long left=0;
        long long right=x;
        long long mid;
        int res;
        while(left<=right){
            mid=left+(right-left)/2;
            if(mid*mid>x){
                right=mid-1;
            }
            else if(mid*mid<x){
                left=mid+1;
                res=mid;
            }
            else{
                return mid;
            }
        }
        return res;
    }
};