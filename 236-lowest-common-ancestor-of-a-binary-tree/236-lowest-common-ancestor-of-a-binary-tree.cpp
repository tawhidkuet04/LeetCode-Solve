/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lca( TreeNode *root, TreeNode *p, TreeNode *q){
        
        if(root == NULL) return root;
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->right, p, q);
        
        if( left != NULL && right != NULL){
            // if(ans == NULL){
            //     ans = root;
            // }
            return root;
        }else if(left == NULL){
           return right;
        }else{
            return left;
        }
        
    }
    
    // 3 5
    // 3 1 8
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = NULL;
        return lca(root, p, q);
    }
};