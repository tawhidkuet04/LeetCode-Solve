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
    
    Node *getRoot( Node *p){
        if(p->parent == NULL) return p;
            
         return getRoot(p->parent);    
        
    }

    Node *getLca(Node *root, Node *p, Node *q){
        if( root == NULL || root == p || root == q) return root;
        
        Node *left = getLca(root->left, p, q);
        Node *right = getLca(root->right, p, q);
        
        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            return root;
        }
        
        
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        Node *root = getRoot(p);
        
        return getLca(root, p, q);
    }
};