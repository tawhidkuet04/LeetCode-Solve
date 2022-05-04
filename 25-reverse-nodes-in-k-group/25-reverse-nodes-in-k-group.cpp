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
    
    
    
    ListNode* reverseGroup(ListNode *head, int remaining, int k){
        if( remaining < k ) return head;
        
        stack<ListNode*> st;
        ListNode *cur = head, *temp = head;
        for(int index = 0; index < k; index ++ ){
            st.push(cur);
            cur = cur->next;
        }
        
        temp->next = reverseGroup(cur, remaining - k, k);
        
        ListNode *last = st.top(), *tempLast = st.top();
        st.pop();
        while(!st.empty()){
            last->next = st.top();
            last = st.top();
            st.pop();
        }
        
        return tempLast;
        
        
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = getLength(head);
        return reverseGroup(head, size, k);
    }
};

// 1 2 3 4 5 6 