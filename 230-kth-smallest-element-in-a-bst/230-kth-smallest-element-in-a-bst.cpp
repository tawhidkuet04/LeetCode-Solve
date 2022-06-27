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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *node = root;
        int cnt = 0;
        
        while(!st.empty()){
            if(node == NULL){
                cnt ++;
                node = st.top();
                st.pop();
                
                if(cnt == k){
                    return node->val;
                }
                if(node->right != NULL) st.push(node->right);
                node = node->right;
                   
            }else{
                if(node->left != NULL) st.push(node->left);
                node = node->left;
            }
        }
        
        return -1;
    }
};