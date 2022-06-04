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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *root = dummy;
        
        while(head != NULL){
             ListNode *nextNode = head->next;
            
            if(nextNode == NULL){
                dummy->next =  head;
                return root->next;
            }
             
            if(head->val != nextNode->val){
                dummy->next = head;
                dummy = head;
            }
            
            head = head->next;
            
            
        }
        
        return NULL;
    }
};