class Solution {
public:
    
    vector<int> dp;
    
    bool solve(vector<int>& nums, int n){
        
        if(n >= nums.size() || n < 0 || nums[n] == -1){
            return 0;
        }
        
        if(nums[n] == 0){
            return 1;
        }
        
        if(dp[n] != -1) return 0;
        
        dp[n] = 1;
        
        bool ahead = solve(nums, n + nums[n]);
        bool backwards = solve(nums, n - nums[n]);
        
        return ahead || backwards;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        dp.resize(n + 1, -1);

        return solve(arr, start);
    }
};

-----