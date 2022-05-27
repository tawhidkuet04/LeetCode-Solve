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
    
    void solve(TreeNode *root, vector<string> &paths, string path){
        if( root == NULL){
            return;
        }
        
        path += to_string(root->val);
        
        if(root->left == NULL && root->right == NULL){
            paths.push_back(path);
            return;
        }
        
        path += "->";
        solve(root->left, paths, path);
        solve(root->right, paths, path);
        
        
      
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, ans, "");
        return ans;
    }
};