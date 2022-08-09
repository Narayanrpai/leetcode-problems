class Solution {
public:
    int dp[50005][3];
    
    int solve(vector<int>& p, int fee, bool state, int i){
        if(i == p.size()){
            return 0;
        }
        if(dp[i][state] != -1){
            return dp[i][state];
        }
        if(state){
            return dp[i][state] = max(-p[i] + solve(p, fee, 0, i + 1), solve(p, fee, 1, i + 1));
        }
        return dp[i][state] = max(p[i] - fee + solve(p, fee, 1, i + 1), solve(p, fee, 0, i + 1));
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp[n+1][2];
        memset(dp, -1, sizeof(dp));
        
        return solve(prices, fee, 1, 0);
    }
};