class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        stack<int>st;
        int n = heights.size();
        vector<int>left(n,-1);
        for(int i = n-1;i>=0;i--){
            while(st.size() >0 && heights[st.top()] <= heights[i]){
                st.pop();
            }
            if(st.size() >0 ){
                left[i] =st.top();
            }
            st.push(i);
        }

        vector<int>ans;
        
        for(auto it:queries){
            int i = it[0];
            int j = it[1];
            if(i>j){
                i = i^j;
                j = i^j;
                i = i ^j;
            }

             if(i == j){
                ans.push_back(j);
             }
             else{
            if(heights[i] >= heights[j] ){
                int p = 0;
                if(left[i]<j && left[i] != -1){
                    for(int k = j+1;k<n;k++){
                        if(heights[k] > heights[i]){
                           ans.push_back(k);
                            p =1;
                           break;
                        }
                        
                    }
                    if(p == 0){
                        ans.push_back(-1);
                    }
                }
                else if(left[i] >= j ){
                    ans.push_back(left[i]);
                }
                else{
                    ans.push_back(-1);
                }
       

               
            }
            else if(heights[i] < heights[j]){
                ans.push_back(j);
            }
            else{
                ans.push_back(-1);
            }

        }
        }
        return ans;
    }
};