class Solution {
public:
    pair<int, int> getRowCol(int i, int n){
    
        int row = (i - 1) / n;
        int col = (i - 1) % n;
        
        if(row % 2){
            col = n - 1 - col;
        }
        return {row, col};
    }
    
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        reverse(board.begin(), board.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j] << ' ';
            }cout << endl;
        }
        
        unordered_set<int> vis;
        queue<pair<int, int>>q;
        q.push({1,0});
        
        while(!q.empty()){
            int block = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            for(int i=1;i<7;i++){
                
                int cell = block + i;
                
                pair<int, int> rowCol = getRowCol(cell, n);
                int row = rowCol.first, col = rowCol.second;            
                
                if(board[row][col] != -1){
                    cell = board[row][col];
                }
                
                if(cell == n * n){
                    return steps + 1;
                }
                
                if(vis.find(cell) == vis.end()){
                    vis.insert(cell);
                    q.push({cell, steps + 1});
                }
            }
        }
        
        return -1;
    }
};