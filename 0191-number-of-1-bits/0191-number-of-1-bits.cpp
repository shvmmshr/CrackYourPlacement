class Solution {
public:
    int decimal2binary(int n){
        int sum=0;
        while(n){
            sum+=n%2;
            n/=2;
        }
        return sum;
    }
    int hammingWeight(int n) {
        long long sum=decimal2binary(n);
        return sum;
    }
};