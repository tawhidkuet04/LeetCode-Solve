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
    
    map<int , vector<pair<int,int>> > mp;
    
    void solve(TreeNode *root, int index, int level){
        
        if(root == NULL) return;
        
        mp[index].push_back({level, root->val});
        
        solve(root->left, index - 1, level + 1);
        solve(root->right, index + 1, level + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector< vector<int> > ans;
        solve(root, 0, 0);
        for(auto &keyVal: mp){
            auto  arr = keyVal.second;
            sort(arr.begin(), arr.end());
            vector<int> verOrder;
            for(auto &val: arr){
                verOrder.push_back(val.second);
            }
            ans.push_back(verOrder);
        }
        
        return ans;
    }
};