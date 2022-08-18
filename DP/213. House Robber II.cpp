class Solution {
public:
    
    int dp[1003][3][3];
    int solve(int n, vector<int>& nums, bool robbedPrev, bool robbedFirst){
        if(n >= nums.size()){
            return 0;
        }
        
        int rob = 0;
        int skip = 0;
        
        if(dp[n][robbedPrev][robbedFirst] != -1){
            return dp[n][robbedPrev][robbedFirst];
        }
        
        if(n == 0){
            rob = nums[n] + solve(n + 1, nums, 1, 1);
            skip = solve(n + 1, nums, 0, 0);
            
            return dp[n][robbedPrev][robbedFirst] = max(rob, skip);
        }
        
        if(n == nums.size() - 1){
            if(!robbedFirst and !robbedPrev){
                rob = nums[n] + solve(n + 1, nums, 1, robbedFirst);
            }
            skip = solve(n + 1, nums, 0, robbedFirst);
            return dp[n][robbedPrev][robbedFirst] = max(rob, skip);
        }
        
        if(!robbedPrev){
            rob = nums[n] + solve(n + 1, nums, 1, robbedFirst);
        }
        
        skip = solve(n + 1, nums, 0, robbedFirst);
        
        return dp[n][robbedPrev][robbedFirst] = max(rob, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp[n + 1][2][2];
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0, 0);
    }
};