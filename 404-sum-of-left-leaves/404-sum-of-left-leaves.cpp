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
    bool isLeaf(TreeNode *node){
        
        return (node != NULL && node->left == NULL && node->right == NULL);
    }
    
    int solve(TreeNode* root, int &sum){
        stack< TreeNode* > st;
        
        st.push(root);
        
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            
            if(isLeaf(node->left)){
                sum += node->left->val;
            }
            
            if(node->left != NULL){
                st.push(node->left);
            }
            
            if(node->right != NULL){
                st.push(node->right);
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