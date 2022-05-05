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
    int solve(TreeNode *root, int &ans){
        if(root == NULL) return 0;
        
        int lf = solve(root->left, ans);
        int rf = solve(root->right, ans);
        if(abs(lf - rf) > 1){
            ans = 0;
            return 0;
        }
        return max(lf, rf) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = 1;
        solve(root, ans);
        if(ans) return  true;
        else return false;
    }
};