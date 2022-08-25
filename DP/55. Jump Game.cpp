class Solution {
public:
    
    vector<int> dp;
    
    bool solve(vector<int>& nums, int n){
        if(n < 0 || n >= nums.size()){
            return false;
        }
        
        if(n == nums.size() - 1){
            return true;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        for(int i = 1; i <= nums[n]; i++){
            bool can = solve(nums, n + i);
            if(can) return dp[n] = true;
        }
        
        return dp[n] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        dp.resize(n + 1, -1);
        
        return solve(nums, 0);
    }
};

