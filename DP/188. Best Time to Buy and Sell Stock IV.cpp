class Solution {
public:
    int dp[1005][3][105];
    
    int solve(vector<int>& p, int k, bool state, int i, int curr){
        if(i == p.size() || curr == k){
            return 0;
        }
        
        if(dp[i][state][curr] != -1){
            return dp[i][state][curr];
        }
        
        if(state){
            return dp[i][state][curr] = max(-p[i] + solve(p, k, 0, i + 1, curr), solve(p, k, 1, i + 1, curr));
        }
        return dp[i][state][curr] = max(p[i] + solve(p, k, 1, i + 1, curr + 1), solve(p, k, 0, i + 1, curr));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp[n+1][2][k+1];
        memset(dp, -1, sizeof(dp));
        
        return solve(prices, k, 1, 0, 0);
    }
};