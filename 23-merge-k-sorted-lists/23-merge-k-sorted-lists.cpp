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
         if(first == NULL) return second ;
         if(second == NULL) return first;
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
        
        for(int index = 1; index < size; index ++){
            lists[index] = mergeTwoList(lists[index], lists[index - 1]);
        }
        
        ListNode *ans = lists[size - 1];
        return ans;
        
    }
};