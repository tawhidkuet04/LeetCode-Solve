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
    
    int solve(TreeNode *node){
        if(node == NULL) return 0;
        
        int left = getLeftHeight(node);
        int right = getRightHeight(node);
        
        if(left == right) return (1 << left) - 1;
        
        return 1 + solve(node->left) + solve(node->right);
        
    }
    
    
    int getLeftHeight(TreeNode *node){
        int height = 0 ;
        
        while(node){
            height ++;
            node = node->left;
        }
        return height;
    }
    
    int getRightHeight(TreeNode *node){
        int height = 0 ;
        
        while(node){
            height ++;
            node = node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};