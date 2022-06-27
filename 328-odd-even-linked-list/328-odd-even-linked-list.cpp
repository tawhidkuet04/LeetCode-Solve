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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        
        ListNode *odd = oddHead, *even = evenHead;
        
        while(odd && even){
            ListNode *oddNext = odd->next->next;
            if(oddNext == NULL){
                odd->next = evenHead;
                return oddHead;
            }
            odd->next = oddNext;
            odd = oddNext;
            
            ListNode *evenNext = even->next->next;
            even->next = evenNext;
            even = evenNext;
            
        }
        
         odd->next = evenHead;
         return oddHead;
    }
    
    
};