/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}https://leetcode.com/problemset/all/
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    // 1  2 - 4
    // 2 4 - 5 
    
     ListNode* mergeTwoList( ListNode *first, ListNode *second){
        ListNode *prevNode = new ListNode(-1);
         
        ListNode *prev = prevNode;
         
        while(first != NULL && second != NULL){
            if(first->val < second->val){
                prevNode->next = first;
                first = first->next;
            }else{
                prevNode->next = second;
                second = second->next;
            }
            prevNode = prevNode->next;
        }
         
       prevNode->next = (first == NULL) ? second : first;
         
        return prev->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int size = lists.size();
        if(size == 0) return NULL;
        if(size <= 1) return lists[0];
        int interval = 1;
        while(interval < size){
             for(int index = 0; index < (size - interval); index += (interval * 2)){
                 lists[index] = mergeTwoList(lists[index], lists[index + interval]);
            }
            
            interval *= 2;
        
        }
       
        ListNode *ans = lists[0];
        return ans;
        
    }
    
    // 1 2 3 4 5
};