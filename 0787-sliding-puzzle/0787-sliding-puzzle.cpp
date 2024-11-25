class Solution {
public:
    string matrixToString(const vector<vector<int>>& board){
        string result;
        for(const auto& row:board){
            for(int num:row){
                result+=to_string(num);
            }
        }
        return result;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> target = {{1,2,3},{4,5,0}};

        queue<pair<vector<vector<int>>,pair<int,int>>> q;
        unordered_set<string> visited;

        int zeroRow,zeroCol;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    zeroRow = i;
                    zeroCol = j;
                    break;
                }
            }
        }

        q.push({board, {zeroRow,zeroCol}});
        visited.insert(matrixToString(board));

        int steps  = 0;

        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [currentBoard,zeroPos] = q.front();
                q.pop();

                if(currentBoard==target){
                    return steps;
                }

                for(auto [dx,dy] : directions){
                    int newRow = zeroPos.first+dx;
                    int newCol = zeroPos.second+dy;

                    if(newRow>=0 && newRow<2 && newCol>=0 && newCol<3){
                        vector<vector<int>> newBoard = currentBoard;

                        swap(newBoard[zeroPos.first][zeroPos.second], newBoard[newRow][newCol]);

                        string newBoardStr = matrixToString(newBoard);

                        if(visited.find(newBoardStr) == visited.end()){
                            visited.insert(newBoardStr);
                            q.push({newBoard, {newRow,newCol}});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};