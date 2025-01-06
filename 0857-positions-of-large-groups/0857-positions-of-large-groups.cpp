class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;

        char ch = s[0];
        int cnt = 0, n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==ch) cnt++;
            else 
            {
                ch = s[i];
                if(cnt > 2)
                    ans.push_back({i-cnt, i-1});
                cnt = 1;
            }
        }
        if(cnt > 2)
            ans.push_back({n-cnt, n-1});
        return ans;
    }
};