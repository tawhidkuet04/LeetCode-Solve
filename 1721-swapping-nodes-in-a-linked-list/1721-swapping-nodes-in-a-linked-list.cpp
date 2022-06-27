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
    int getLength(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            head = head->next;
            cnt ++;
        }
        return cnt;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int length = getLength(head);
        
        int firstLength = k, secondLength = length - k;
        
        ListNode *firstHead = head, *secondHead = head;
        
        int cnt = 1;
        while(cnt < firstLength){
            firstHead = firstHead->next;
            cnt ++;
        }
        
        cnt = 0;
        
         while(cnt < secondLength){
            secondHead = secondHead->next;
            cnt ++;
        }
        
        int temp = firstHead->val;
        firstHead->val = secondHead->val;
        secondHead->val = temp;
        
        return head;
        
        
    }
};


// head = [1,2,3,4,5], k = 2
    
//     1 3 4  6 /9  1 5 7