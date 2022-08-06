class Solution {
public:
    
    int dp[1005][1005];
    
    bool solve(string& s, int i, int j){
        if (i >= j){        
            return true;
        }
        if (s[i] != s[j]){
            return false;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] = solve(s, i + 1, j - 1);
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        dp[n + 1][n + 1];
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = n - 1; j >= i; j--){
                dp[i][j] = solve(s, i, j);
                
                if(dp[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};