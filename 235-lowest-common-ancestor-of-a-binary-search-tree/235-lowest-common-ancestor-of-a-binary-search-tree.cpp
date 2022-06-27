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
    
    TreeNode *solve(TreeNode* root, TreeNode* p, TreeNode* q){
        
        int rootVal = root->val;
        if(rootVal < p->val && rootVal < q->val){
            return solve(root->right, p, q);
        }else  if(rootVal > p->val && rootVal > q->val){
            return solve(root->left, p, q);
        }else{
             return root;
        }
       
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
         return solve(root,p,q);
    }
};