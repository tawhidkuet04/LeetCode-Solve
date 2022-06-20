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
    
    bool isValid(TreeNode *node, long long lo, long long hi){
        if(node == NULL) return true;
        
        if( !(node->val > lo && node->val < hi)){
            return false;
        }
        
        if(isValid(node->left, lo, node->val) && isValid(node->right, node->val , hi)){
            return true;
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};