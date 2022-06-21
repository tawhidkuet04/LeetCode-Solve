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
    
    ListNode *mergeTwoList(ListNode *first, ListNode *second){
        
        ListNode *dummy = new ListNode(-1);
        
        ListNode *head = dummy;
        
        while(first != NULL && second != NULL){
            if(first->val < second->val){
                dummy->next = first;
                dummy = first;
                first = first->next;
            }else{
                dummy->next = second;
                dummy = second;
                second = second->next;
            }
        }
        
        while(first != NULL){
            dummy->next = first;
            dummy = first;
            first = first->next;
        }
        
         while(second != NULL){
            dummy->next = second;
            dummy = second;
            second = second->next;
        }
        
        return head->next;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        int index = 0, power = 1, sz = lists.size(), k = 2;
        
        while(true){
            if(index == 0 && (index + power) >= sz) break;
            for(int index = 0; index < sz; index += k){
                if(index + power >= sz) break;
                lists[index] = mergeTwoList(lists[index], lists[index + power]);
            }
            
            k *= 2;
            power *= 2;
            
        }
        
        return lists[0];
    }
};