class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0,d=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        set<pair<int,int>> s;
        for(auto i:obstacles){
            s.insert({i[0],i[1]});
        }
        int ans=0;
        for(auto i:commands){
            if(i==-2) d=(d+3)%4;
            else if(i==-1) d=(d+1)%4;
            else{
                for(int j=0;j<i;j++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(s.find({nx,ny})!=s.end()) break;
                    x=nx;
                    y=ny;
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};