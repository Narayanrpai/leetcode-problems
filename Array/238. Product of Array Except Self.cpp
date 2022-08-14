/*
O(N) Memory used -

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n), rightProd(n);
        
        leftProd[0] = 1;
        for(int i = 1; i < n; i++){
            leftProd[i] = leftProd[i - 1] * nums[i - 1];
        }
        
        rightProd[n-1] = 1;
        for(int i = n - 2; i >= 0; i--){
            rightProd[i] = rightProd[i + 1] * nums[i + 1];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = leftProd[i] * rightProd[i];
        }
        
        return ans;
    }
};
*/

// O(1) Memory Solution 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftProd = 1, rightProd = 1;
        
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++){
            ans[i] *= leftProd;
            leftProd *= nums[i];
        }
        
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= rightProd;
            rightProd *= nums[i];
        }
        
        return ans;
    }
};

