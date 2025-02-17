class Solution {
public:
    int Perm(int n, vector<int>& cnt, int k) {
        if (n == 1)
            return k - count(cnt.begin(), cnt.end(), 0);
        
        int res = 0;
        for (int i = 0; i < k; i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                res += Perm(n - 1, cnt, k);
                cnt[i]++;
            }
        }
        return res;
    }

    int numTilePossibilities(string& tiles) {
        int k = 0, n = tiles.size();
        vector<int> cnt(26, 0);
        
        for (char c : tiles)
            if (++cnt[c - 'A'] == 1) k++;
        
        sort(cnt.begin(), cnt.end(), greater<int>());
        cnt.resize(k);
    
        int ans = 0;
        for (int len = 1; len <= n; len++) 
            ans += Perm(len, cnt, k);
        
        return ans;
    }
};