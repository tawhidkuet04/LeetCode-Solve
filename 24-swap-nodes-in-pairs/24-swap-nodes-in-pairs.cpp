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
    

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
      
        ListNode *firstNode = head, *secondNode;
        
        ListNode *startNode = firstNode->next, *prev = new ListNode(-1);
        
        while(firstNode != NULL){
            if(firstNode->next == NULL) return  startNode;
            
            secondNode = firstNode->next;
            ListNode *temp = secondNode->next;
            
            prev->next = secondNode;
            secondNode->next = firstNode;
            firstNode->next = temp;
           
            prev = firstNode;
            firstNode = firstNode->next;
            
//                ListNode *temp = firstNode;
//                firstNode = secondNode;
//                secondNode = temp;
               
            
            
        }
        
        // 1 2 3 4
            
            
        
        return startNode;
    }
};