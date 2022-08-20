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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL or head->next == NULL) return;
        
        ListNode* left = head->next;
        
        ListNode* mid = getMid(head);
        
        ListNode* right = reverseList(mid);
        
        int state = 0;
        while(left != right){
            if(state & 1){
                head->next = left;
                left = left->next;
            }
            else{
                head->next = right;
                right = right->next;
            }
            state++;
            head = head->next;
        }
    }
};

