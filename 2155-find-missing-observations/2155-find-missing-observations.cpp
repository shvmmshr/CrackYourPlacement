class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int m=rolls.size();
        int totalsum=mean*(n+m);
        int sum=0;
        for(auto i : rolls){
            sum+=i;
        }
        if(totalsum-sum>6*n || sum>totalsum || totalsum-sum<n) return res;
        else {
            int diff=totalsum-sum;
            int avg=diff/n;
            int rem=diff%n;
            for(int i=0;i<n;i++){
                res.push_back(avg);
            }
            for(int i=0;i<rem;i++){
                res[i]++;
            }
            return res;
        }
    }
};