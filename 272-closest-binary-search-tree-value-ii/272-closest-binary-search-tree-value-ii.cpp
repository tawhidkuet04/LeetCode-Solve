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
    
    void solve(TreeNode *root, double target, int k,   vector< pair<double, int> > &diff){
        if(root == NULL){
            return;
        }
        diff.push_back(make_pair( fabs((double) root->val - target), root->val));
        
        solve(root->left, target, k, diff);
        solve(root->right, target, k, diff);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector< pair<double, int> > diff;
        
        solve(root, target, k, diff);
        
        sort(diff.begin(),diff.end());
        
        vector<int> ans;
        
        for(auto pair: diff){
            
            ans.push_back(pair.second);
            if(ans.size() == k) break;
        }
        
        return ans;
    }
};