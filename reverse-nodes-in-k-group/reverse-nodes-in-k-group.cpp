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
        int count = 0;
        
        while(head != NULL){
            head = head->next;
            count ++;
        }
        
        return count;
    }
    
    
//        first   
           
//      p tf next
//   
  // prev 1 2 3 4 5 6 7 8 
        
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = getLength(head);
           
        if( size < k || k <= 1) return head;
           
           
        ListNode *first = head, *prev = new ListNode(-1), *startNode;
           
        int remaining = size;
           
        bool flag = false;
           
    
           
        while(first != NULL && remaining){
            if(remaining < k) return startNode;
            
            ListNode *cur = first, *curPrev = prev;
            int count = k;
            ListNode *next;
            
            while(count -- &&  cur != NULL){
                next = cur->next;
                cur->next = curPrev;
                curPrev = cur;
                cur = next;
            }
            
            // return curPrev;
            // 1 2 3 cur
            
            if(!flag){
                flag = true;
                startNode = curPrev;
            }
            
            prev->next = curPrev;
            
            prev = first;
            first->next = cur;
            first = cur;
            
            remaining -= k;
        }
           
           
        return startNode;
       
    }
};

// 1 2 3 4 5 6 