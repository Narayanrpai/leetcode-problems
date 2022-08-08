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


-------------------------------------------------------------------------------------------------------------
Tabulation nx2x2 ( ͡° ͜ʖ ͡°)

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][3][3];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                dp[n][i][j] = 0;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int state=0;state<=1;state++){
                for(int cooldown=0;cooldown<=1;cooldown++){
                    if(cooldown == 1){
                        dp[i][state][cooldown] = dp[i+1][state][0];
                    }
                    else{
                        if(state == 1){
                            dp[i][state][cooldown] = max(-prices[i] + dp[i+1][0][cooldown], dp[i+1][1][cooldown]);
                        }
                        else{
                            dp[i][state][cooldown] = max(prices[i] + dp[i+1][1][1], dp[i+1][0][cooldown]);
                        }
                    }
                }
            }
        }
        return dp[0][1][0];
    }

-------------------------------------------------------------------------------------------------------------
Memory optimization - O(3x3) with TC - O(Nx3x3) (⌐■_■)

        for(int i=n-1;i>=0;i--){
            for(int state=0;state<=1;state++){
                for(int cooldown=0;cooldown<=1;cooldown++){
                    if(cooldown == 1){
                        prev[state][cooldown] = after[state][0];
                    }
                    else{
                        if(state == 1){
                            prev[state][cooldown] = max(-prices[i] + after[0][cooldown], after[1][cooldown]);
                        }
                        else{
                            prev[state][cooldown] = max(prices[i] + after[1][1], after[0][cooldown]);
                        }
                    }
                }
            }
            after = prev;
        }
        return after[1][0];
    } 