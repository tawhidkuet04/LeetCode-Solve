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
    
    string dfs(TreeNode *node, unordered_map<string,TreeNode *> &mp,
              unordered_map<string,int> &cntMp){
        if(node == NULL) return "";
        
        string left = dfs(node->left, mp, cntMp);
        string right = dfs(node->right, mp, cntMp);
        
        string subTree = to_string(node->val) + "," + left + "," + right;
        
        mp[subTree] = node;
        cntMp[subTree] ++ ;
        
        return subTree;
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         unordered_map<string,TreeNode* > mp;
         unordered_map<string,int> cntMp;
        
        dfs(root, mp, cntMp);
    
        vector<TreeNode*> ans;
        
        for(auto &keyVal: cntMp){
            if(keyVal.second > 1){
                ans.push_back(mp[keyVal.first]);
            }
        }
        
        return ans;
    }
};

// 1243244