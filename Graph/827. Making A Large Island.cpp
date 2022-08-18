class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& grid, int id){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = id;
        
        return 1 + dfs(i + 1, j, grid, id) + dfs(i - 1, j, grid, id) + dfs(i, j + 1, grid, id) + dfs(i, j - 1, grid, id);
    }
    
    void adjacentIslands(int i, int j, int n, vector<vector<int>>& grid, unordered_set<int>& s){
        if(i + 1 < n){
            s.insert(grid[i + 1][j]);
        }
        if(i - 1 >= 0){
            s.insert(grid[i - 1][j]);
        }
        if(j + 1 < n){
            s.insert(grid[i][j + 1]);
        }
        if(j - 1 >= 0){
            s.insert(grid[i][j - 1]);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int maxArea = INT_MIN;
        unordered_map<int, int> area;
        
        int id = 2;     // 0 and 1 are part of the grid's main elements
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area[id] = dfs(i, j, grid, id);
                    maxArea = max(maxArea, area[id]);   // to find if the largest island is formed without the operation
                    id++;
                }
            }
        }
        
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> s;
                    adjacentIslands(i, j, n, grid, s);
                    int op = 1;      //including the operation 
                    for(auto& id : s){
                        op += area[id];
                    }
                    maxArea = max(maxArea, op);
                }
            }
        }
        
        return maxArea;
    }
};