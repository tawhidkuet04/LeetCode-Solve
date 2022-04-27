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
    
    ListNode* solve(ListNode *head){
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        
        ListNode *firstNode = head;
        ListNode *secondNode = head->next;
        
        firstNode->next = solve(secondNode->next);
        secondNode->next = firstNode;
        
        return secondNode;
        
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        return solve(head);
    }
};