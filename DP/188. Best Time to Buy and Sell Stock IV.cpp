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

-------------------------------------------------------------------------------------------------------------
Tabulation SC O(n*2*k) TC O(n*2*k) :|

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2*k+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j % 2 == 0){
                    dp[i][j] = max(-prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
            }
            
        }
        return dp[0][0];
    }
};

-------------------------------------------------------------------------------------------------------------
Memory Optimized O(2*k + 2*k)

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> pre(2*k+2, 0), after(2*k+2, 0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j % 2 == 0){
                    pre[j] = max(-prices[i] + after[j+1], after[j]);
                }
                else{
                    pre[j] = max(prices[i] + after[j+1], after[j]);
                }
            }
            after = pre;
        }
        return after[0];
    }
};