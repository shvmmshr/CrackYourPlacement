class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        int left=nums[0][0];
        int right=nums[0][0];
        for(int i=0;i<k;i++){
            vector<int> l=nums[i];
            left=min(left,l[0]);
            right=max(right,l[0]);
            pq.push({l[0],{i,0}});
        }
        vector<int> result={left,right};
        while(true){
            int n,i,idx;
            n=pq.top().first;
            i=pq.top().second[0];
            idx=pq.top().second[1];
            if(idx==nums[i].size()-1){
                break;
            }
            int nextval;
            nextval=nums[i][idx+1];
            pq.pop();
            pq.push({nextval,{i,idx+1}});
            left=pq.top().first;
            right=max(right,nextval);
            if(right-left<result[1]-result[0]){
                result={left,right};
            }
        }
        return result;
    }
};