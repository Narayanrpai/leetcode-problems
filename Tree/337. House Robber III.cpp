/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
    
    int getLen(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + getLen(root->left) + getLen(root->right);
    }
    
    int solve(TreeNode* root, bool robbedPrev){
        if(root == NULL){
            return 0;
        }
        
        if(dp[root][robbedPrev]){
            return dp[root][robbedPrev];
        }
        
        int rob = 0, skip = 0;
        
        if(!robbedPrev){
            rob = root->val + solve(root->left, 1) + solve(root->right, 1);
        }
        
        skip = solve(root->left, 0) + solve(root->right, 0);
        
        return dp[root][robbedPrev] = max(rob, skip);
    }
    
    int rob(TreeNode* root) {
        
        return solve(root, 0);
    }
};