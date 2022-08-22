class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || grid[i][j] == -1){
            return 0;
        }
        
        int temp = grid[i][j];
        grid[i][j] = -1;
        
        int left = temp + solve(grid, m, n, i, j - 1);
        int right = temp + solve(grid, m, n, i, j + 1);
        int up = temp + solve(grid, m, n, i - 1, j);
        int down = temp + solve(grid, m, n, i + 1, j);
        
        grid[i][j] = temp;
        
        return max(left, max(max(right, up), down));
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int maxArea = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0)
                    maxArea = max(maxArea, solve(grid, m, n, i, j));
            }
        }
        if(maxArea == INT_MIN) return 0;
        
        return maxArea;
    }
};

