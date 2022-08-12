class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for(int i=0;i<n-2;i++){
            
            if(i != 0 && (nums[i] == nums[i-1])){
                continue;
            }
            
            int l = i + 1, r = n - 1;
            
            while(l < r){
                
                int target = nums[i] + nums[l] + nums[r];
                
                if(target > 0){
                    r--;
                }
                else if(target < 0){
                    l++;
                }
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                
                    while(l+1 < r and nums[l] == nums[l+1]){        // skip duplicate pairs and point to last occurence of a num
                        l++;
                    }
                    while(r-1 >= l and nums[r] == nums[r-1]){
                        r--;
                    }
                    l++, r--; //update indices
                }
            }
        }

        return ans;
    }
};