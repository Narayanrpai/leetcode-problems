class Solution {
public:
    int dp[1005][1005];
    bool solve(string& s, int i, int j){
        if(i >= j){
            return true;
        }
        
        if(s[i] != s[j]){
            return false;
        }        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] = solve(s, i+1, j-1);
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        dp[n+1][n+1];
        memset(dp, -1, sizeof(dp));
        int maxLen = INT_MIN, maxi = 0, maxj = 0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(dp[i][j] == -1)
                dp[i][j] = solve(s, i, j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dp[i][j] == 1 && ((j - i) > maxLen)){
                    maxLen = j - i;
                    maxi = i, maxj = j;
                }
            }
        }
        return s.substr(maxi, maxj - maxi + 1);
    }
};