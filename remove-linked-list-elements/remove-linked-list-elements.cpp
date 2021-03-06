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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        ListNode *newHead = dummy;
        ListNode *temp = head;
        while( temp != NULL){
            if(temp->val != val){
                dummy->next = temp;
                dummy = temp;
            }
            temp = temp->next;
        }
        dummy->next = NULL;
        return newHead->next;
        
    }
};