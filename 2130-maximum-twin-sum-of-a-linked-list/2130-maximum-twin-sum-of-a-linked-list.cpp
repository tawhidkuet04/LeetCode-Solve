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
    int getLength(ListNode *head){
        int length = 0 ;
        while(head != NULL){
            head = head->next;
            length ++ ;
        }
        return length;
    }
    
    int pairSum(ListNode* head) {
        int length = getLength(head);
        
        ListNode *prev = NULL, *cur = head;
        
        int count = 0 ;
        
        while(cur != NULL){
            if(count > (length/2)){
                ListNode *next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }else{
                prev = cur ;
                cur = cur->next;
            }
            count ++;
        }
        
        int half = length /2, mx = 0;
        
        ListNode *start = head, *end = prev;
        
        while(half--){
            int sum = start->val  + end->val;
            
            mx = max(sum, mx);
            
            start = start->next;
            end = end->next;
        }
        
        return mx;
        
        
        
        
    }
};