class Solution {
public:
    long long minimumSteps(string s) {
        long long count=0;
        long long n=0;
        for(auto c:s){
            if(c=='1') n++;
            if(c=='0') count+=n;
        }
        return count;
    }
};