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
    vector< vector<int> > levelOrder(TreeNode *root){
        queue<TreeNode *> q ;
        
        q.push(root);
        
        vector< vector<int> > ans;
        
        if(root == NULL) return ans;
        
        bool flip = true;
        
        while(!q.empty()){
            int qSize = q.size();
            vector<int> levelNodes;
            for(int index = 0; index < qSize; index ++ ){
                TreeNode *node = q.front();
                q.pop();
                
                levelNodes.push_back(node->val);
                
                if(node->left != NULL){
                    q.push(node->left);
                }
                
                if(node->right != NULL){
                    q.push(node->right);
                }

            }
            
            if(!flip){
                reverse(levelNodes.begin(), levelNodes.end());
            }
            flip = !flip;
            ans.push_back(levelNodes);
        }
        return ans;
        
        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
    }
};