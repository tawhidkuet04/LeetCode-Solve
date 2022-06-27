/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* build(TreeNode *root, int val){
        if(root == NULL){
            return new TreeNode(val);
        }
        
        if(val > root->val){
            root->right = build(root->right, val);
        }else{
            root->left = build(root->left, val);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode *root = NULL;
        
       for(int index = 0; index < preorder.size(); index ++ ){
           if(index == 0){
               root = build(root, preorder[index]);
           }else{
               build(root, preorder[index]);
           }
           
       }
        return root;
        
    }
};