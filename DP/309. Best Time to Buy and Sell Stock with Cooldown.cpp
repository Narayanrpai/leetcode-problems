class Solution {
public:
    int dp[5005][3][3];
    
    int solve(vector<int>& p, int i, bool state, bool cooldown){
        if(i == p.size()){
            return 0;
        }
        
        if(dp[i][state][cooldown] != -1){
            return dp[i][state][cooldown];
        }
        
        if(cooldown){
            return dp[i][state][cooldown] = solve(p, i + 1, state, 0);
        }
        
        if(state){
            return dp[i][state][cooldown] = max(-p[i] + solve(p, i + 1, 0, cooldown), solve(p, i + 1, 1, cooldown));
        }
        
        return dp[i][state][cooldown] = max(p[i] + solve(p, i + 1, 1, 1), solve(p, i + 1, 0, cooldown));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp[n+1][2][2];
        memset(dp, -1, sizeof(dp));
        
        return solve(prices, 0, 1, 0);
    }
};