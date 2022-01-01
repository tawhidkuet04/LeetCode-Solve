/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLengthOfList(ListNode *node){
        int length = 0 ;
        while(node != NULL){
            length ++ ;
            node = node->next;
        }
        return length;
    }
    
    ListNode *getStartingNode(ListNode* node, int remainLength){
        int count = 0;
        while(node->next != NULL && count < remainLength){
            node = node->next;
            count ++ ;
        }
        return node;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int listALength = getLengthOfList(headA);
        int listBLength = getLengthOfList(headB);
        
        int remainLength;
        ListNode *startNode, *secondNode;
        
        if( listALength > listBLength){
            remainLength = listALength - listBLength;
            startNode = getStartingNode(headA, remainLength);
            secondNode = headB;
        }else{
            remainLength = listBLength - listALength;
            startNode = getStartingNode(headB, remainLength);
            secondNode = headA;
        }
        
        while(startNode != secondNode && startNode != NULL && secondNode != NULL){
            startNode = startNode->next;
            secondNode = secondNode->next;
        }
        if( startNode == secondNode){
            return startNode;
        }else{
            return NULL;
        }
        
        
        
        
    }
};