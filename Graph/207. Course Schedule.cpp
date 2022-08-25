class Solution {
public:
    vector<int> vis;
    bool dfs(int v, unordered_map<int, vector<int>>& graph){
        if(vis[v]) return false;
        
        if(!graph[v].size()) return true;
        
        vis[v] = 1;
        
        for(auto& u: graph[v]){
            if(!dfs(u, graph)) return false;
        }   
        vis[v] = 0;
        graph[v].clear();
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> graph;
        int n = p.size();
        for(int i=0;i<n;i++){
            graph[p[i][0]].push_back(p[i][1]);
        }
        
        vis.resize(numCourses + 1, 0);
        
        for(int i=0;i<numCourses;i++){
            if(!dfs(i, graph)) return false;
        }
        return true;
    }
};

