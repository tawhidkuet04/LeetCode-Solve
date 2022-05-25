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
    int solve(TreeNode *root, unordered_map<int, vector<int> > &mp){
        if(root == NULL) return 0;
        
        int left = solve(root->left, mp);
        int right = solve(root->right, mp);
        
        int heightFromLeaf = max(left, right) + 1;
        
        mp[heightFromLeaf].push_back(root->val);
        
        return heightFromLeaf;
        
    }
    
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        unordered_map<int, vector<int> > mp;
        
        int maxH = solve(root, mp);
        
        vector< vector<int> > ans;
        
        for(int index = 1 ; index <= maxH; index ++ ){
            ans.push_back(mp[index]);
        }
        
        return ans;
        
    }
};