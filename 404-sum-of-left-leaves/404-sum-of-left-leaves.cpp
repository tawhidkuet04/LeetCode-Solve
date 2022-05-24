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
    
    int solve(TreeNode* root, int &sum){
        stack< pair<TreeNode*, bool> > st;
        
        st.push(make_pair(root, false));
        
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            
            TreeNode *node = top.first;
            bool isFromLeft = top.second;
            
            if(node != NULL){
            if(node->left == NULL && node ->right == NULL){
                if(isFromLeft){
                    sum += node->val;
                }
            }
            
            if(node->left != NULL){
                st.push(make_pair(node->left, true));
            }
            
            if(node -> right != NULL){
                st.push(make_pair(node->right, false));
            }
        }   
            
        }
        
        return sum;
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        
        // dfs(root, false, ans );
        solve(root, ans);
        return ans;
    }
};