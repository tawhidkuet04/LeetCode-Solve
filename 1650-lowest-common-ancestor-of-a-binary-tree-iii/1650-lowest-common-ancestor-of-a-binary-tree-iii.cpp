/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    int getLengthFromRoot(Node *temp){
        int cnt = 0;
        
        while(temp != NULL){
            temp = temp->parent;
            cnt ++;
        }
        
        return cnt;
    }

    Node* goToEqualDepth(Node *temp, int depth){
        while(depth --){
            temp = temp->parent;
        }
        return temp;
    }
    
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
           
        Node *pCopy = p;
        Node *qCopy = q;
        
        int pLength = getLengthFromRoot(pCopy);
        int qLength = getLengthFromRoot(qCopy);
        
        if(pLength > qLength){
            p = goToEqualDepth(p, pLength - qLength);
        }else{
            q =  goToEqualDepth(q, qLength - pLength);
        }
        
        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        
        return p;
          
    }
};