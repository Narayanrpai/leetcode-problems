class Solution {
public:
    vector<int> dp;
    
    int solve(vector<int>& nums, int n){
        if(n >= nums.size()){
            return INT_MAX - 1;
        }
        
        if(n == nums.size() - 1){
            return 0;
        }
        
        if(dp[n] != -1) return dp[n];
        
        int minSteps = INT_MAX - 1, steps;
        for(int i=1;i<=nums[n];i++){
            minSteps = min(minSteps, 1 + solve(nums, n + i));
        }
        
        return dp[n] = minSteps;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        dp.resize(n + 1, -1);
            
        return solve(nums, 0);
    }
};

