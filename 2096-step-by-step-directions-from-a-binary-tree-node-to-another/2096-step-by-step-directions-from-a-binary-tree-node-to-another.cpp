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
    TreeNode * getLca(TreeNode* root, int startValue, int destValue){
        
        if(root == NULL) return root;
        
        if(root->val == startValue || root->val == destValue){
            return root;
        }
        
        TreeNode *left = getLca(root->left, startValue, destValue);
        TreeNode *right = getLca(root->right, startValue, destValue);
        
        if(left != NULL && right != NULL){
            return root;
        }else if (left == NULL){
            return right;
        }else{
            return left;
        }
        
    }
    
    
    bool getPath(TreeNode *root, int target, string &path){
        if(root == NULL){
            return false;
        }
        if(root->val == target){
            return true;
        }
        
        path += 'L';
        if(getPath(root->left , target, path)){
            return true;
        }
        path.pop_back();
        path += 'R';
        if(getPath(root->right , target, path)){
            return true;
        }
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode *lca = getLca(root, startValue, destValue);
        
        
        
        string leftPath = "", rightPath = "";
        
         getPath(lca, startValue, leftPath);
         for(int index = 0; index < leftPath.size(); index ++ ){
                leftPath[index] = 'U';
         }
         getPath(lca, destValue,rightPath);

         return leftPath + rightPath; 
        
    }
};