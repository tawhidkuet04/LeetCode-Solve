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
    
    TreeNode* inorderSuccesor(TreeNode *node){
        TreeNode *root = node;
        while(root->left != NULL){
            root = root->left;
        }
        // cout << node->val << endl;
        return root;
    }
    
    TreeNode *delNode(TreeNode *root, int key){
        if(root == NULL) return root;
        
        if(root->val > key){
             root->left = delNode(root->left, key);
        }
         if(root->val < key){
          root->right = delNode(root->right, key);
         }
        
      
        
        if(root->val == key){
            if(root->left != NULL & root->right != NULL){
                TreeNode *node = inorderSuccesor(root->right);
                root->val = node->val;
                int val = node->val;
                TreeNode *temp =  delNode(root->right, val);
                root->right = temp;
                return root;
                
            }else if(root->left == NULL){
                TreeNode *temp = root->right;
                return temp;
            }else {
                TreeNode *temp = root->left;
                return temp;
            }
        }else{
              return root;
        }
        
      
        
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delNode(root, key);
    }
};