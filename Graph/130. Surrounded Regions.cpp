class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O'){
            return;
        }
        
        board[i][j] = '1';
        
        dfs(i + 1, j, board), dfs(i - 1, j, board), dfs(i, j + 1, board), dfs(i, j - 1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0;i<m;i++){
            dfs(i, 0, board), dfs(i, n - 1, board);
        }
        
        for(int j=0;j<n;j++){
            dfs(0, j, board), dfs(m - 1, j, board);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};