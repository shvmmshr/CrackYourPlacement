#define ll long long
#define vi vector<int>
class Solution {
public:
    std::vector<int> zigzagTraversal(std::vector<std::vector<int>>& grid){
        vi result;
        ll m = grid.size();
        ll n = grid[0].size();
        bool skip = false;

        ll i = 0;
        while (i < m) {
            if (i % 2 == 0) {
                ll j = 0;
                while (j < n) {
                    if (!skip) {
                        result.push_back(grid[i][j]);
                    }
                    skip = !skip;
                    j++;
                }
            } else {
                ll j = n - 1;
                while (j >= 0) {
                    if (!skip) {
                        result.push_back(grid[i][j]);
                    }
                    skip = !skip;
                    j--;
                }
            }
            i++;
        }
        return result;
    }
};