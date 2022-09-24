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
    
    void solve(TreeNode* root, int sum, int targetSum, vector<int> path,
                 vector<vector<int>> &ans ){
        
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root-> right == NULL){
            
            if(sum + root->val == targetSum){
                 path.push_back(root->val);
                 ans.push_back(path);
              
            }
            return;
        
        }
        
        
        path.push_back(root->val);
        solve(root->left, sum + root->val, targetSum, path, ans );
        solve(root->right, sum + root->val,targetSum,  path, ans);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>  ans;

         solve(root, 0, targetSum, vector<int>(), ans);
        
        return ans;
    }
};