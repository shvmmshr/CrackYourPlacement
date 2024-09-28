class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long sum=0;
        sort(maximumHeight.begin(),maximumHeight.end());
        int k=maximumHeight[maximumHeight.size()-1];
        for(int i=maximumHeight.size()-1;i>=0;i--){
            if(k>=maximumHeight[i]){
                k=maximumHeight[i];
            }
            sum+=k;
            k--;
            if(k<0){
                return -1;
            }
            if(i!=0 && k==0){
                return -1;
            }
        }
        return sum;
    }
};