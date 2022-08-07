/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> ans;
        vector<int> list, stack;
    
        while(head != NULL){
            list.push_back(head->val);
            head = head->next;
        }
        
        int n = list.size();
        
        for(int i = n-1; i >= 0; i--){
            
            while(!stack.empty() and stack.back() <= list[i]){
                stack.pop_back();
            }
            
            if(stack.size() == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(stack.back());
            }
            
            stack.push_back(list[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};