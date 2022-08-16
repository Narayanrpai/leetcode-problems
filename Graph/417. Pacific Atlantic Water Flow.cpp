class Solution {
public:
    
    vector<vector<int>> atlantic, pacific, ans;
    
    void flow_pacific(int i, int j, int n, int m, vector<vector<int>>& pac, vector<vector<int>>& heights){
        if(pac[i][j]){
            return;
        }
        
        pac[i][j] = 1;
        
        if(pacific[i][j] && atlantic[i][j]){
            ans.push_back({i, j});
        }
        
        if(i + 1 < m and heights[i + 1][j] >= heights[i][j]){
            flow_pacific(i + 1, j, n, m, pacific, heights);
        }
        if(i - 1 >= 0 and heights[i - 1][j] >= heights[i][j]){
            flow_pacific(i - 1, j, n, m, pacific, heights);
        }
        if(j + 1 < n and heights[i][j + 1] >= heights[i][j]){
            flow_pacific(i, j + 1, n, m, pacific, heights);
        }
        if(j - 1 >= 0 and heights[i][j - 1] >= heights[i][j]){
            flow_pacific(i, j - 1, n, m, pacific, heights);
        }
    }
    
    void flow_atlantic(int i, int j, int n, int m, vector<vector<int>>& atl, vector<vector<int>>& heights){
        if(atl[i][j]){
            return;
        }
        
        atl[i][j] = 1;
        
        if(pacific[i][j] && atlantic[i][j]){
            ans.push_back({i, j});
        }
        
        if(i + 1 < m and heights[i + 1][j] >= heights[i][j]){
            flow_atlantic(i + 1, j, n, m, atlantic, heights);
        }
        if(i - 1 >= 0 and heights[i - 1][j] >= heights[i][j]){
            flow_atlantic(i - 1, j, n, m, atlantic, heights);
        }
        if(j + 1 < n and heights[i][j + 1] >= heights[i][j]){
            flow_atlantic(i, j + 1, n, m, atlantic, heights);
        }
        if(j - 1 >= 0 and heights[i][j - 1] >= heights[i][j]){
            flow_atlantic(i, j - 1, n, m, atlantic, heights);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        atlantic.resize(m + 1, vector<int>(n + 1, 0));
        pacific.resize(m + 1, vector<int>(n + 1, 0));
    
        for(int i=0;i<n;i++){
            flow_pacific(0, i, n, m, pacific, heights);
            flow_atlantic(m-1, i, n, m, atlantic, heights);
        }
        
        for(int i=0;i<m;i++){
            flow_pacific(i, 0, n, m, pacific, heights);
            flow_atlantic(i, n-1, n, m, atlantic, heights);
        }
        
        return ans;
    }
};