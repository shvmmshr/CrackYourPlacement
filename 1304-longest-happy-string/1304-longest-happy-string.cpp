class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        while(pq.empty()!=true){
            auto [count1, c1]=pq.top(); pq.pop();
            if(res.size()>=2 && res.back()==c1 && res[res.size()-2]==c1){
                if(pq.empty()) break;
                auto [count2, c2]=pq.top(); pq.pop();
                res+=c2;
                count2--;
                if(count2) pq.push({count2, c2});
            }else{
                res+=c1;
                count1--;
            }
            if(count1) pq.push({count1, c1});

        }
        return res;

        
    }
};