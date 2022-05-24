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
    void dfs(TreeNode* root, bool isFromLeft, int &sum){
        if(root == NULL) return ;
        if(root ->left == NULL && root->right == NULL){
            if(isFromLeft){
                sum += root->val;
            }
            return;
        }
        
        dfs(root->left, true, sum);
        dfs(root->right, false, sum);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        
        dfs(root, false, ans );
        
        return ans;
    }
};