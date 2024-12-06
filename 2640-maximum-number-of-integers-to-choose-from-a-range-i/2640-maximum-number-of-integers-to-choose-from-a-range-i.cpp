class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> mpp(banned.begin(),banned.end());
        int count=0;
        int sum=0;
        int i=1;
        while(i<=n&&sum+i<=maxSum){
            if(mpp.find(i)==mpp.end()){
                count++;
                sum+=i;
            }
            i++;
        }
        return count;
    }
};