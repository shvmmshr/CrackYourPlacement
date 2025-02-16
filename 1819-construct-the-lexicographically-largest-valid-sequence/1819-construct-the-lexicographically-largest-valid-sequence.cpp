class Solution {
public:
    bool solve(int i,int n,vector<int>& ans,vector<bool>& isUsed){
        if(i>=ans.size()){
            return true;
        }
        if(ans[i]!=-1){
            return solve(i+1,n,ans,isUsed);
        }
        for(int num=n;num>0;num--){
            if(isUsed[num]) continue;

            ans[i]=num;
            isUsed[num]=true;
            if(num==1){
                if(solve(i+1,n,ans,isUsed)==true) return true;
            }else{
                int j=i+num;
                if(j<ans.size() && ans[j]==-1){
                    ans[j]=num;
                    if(solve(i+1,n,ans,isUsed)==true) return true;
                        ans[j]=-1;
                }
            }
            ans[i]=-1;
            isUsed[num]=false;

        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,-1);
        vector<bool> isUsed(n+1,false);
        solve(0,n,ans,isUsed);
        return ans;
    }
};