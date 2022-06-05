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
    
    
    void getPath(TreeNode *root, int target, string &path, string &orgPath){
        if(root == NULL){
            return;
        }
        if(root->val == target){
            orgPath = path;
            return;
        }
        
        path += 'L';
        getPath(root->left , target, path, orgPath);
        path.pop_back();
        path += 'R';
        getPath(root->right , target, path, orgPath);
        path.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode *lca = getLca(root, startValue, destValue);
        
        
        
        string leftPath = "", rightPath = "", path = "";
        
        if(lca->val == startValue){
            getPath(lca, destValue, path, leftPath);
            return leftPath;
        }else  if(lca->val == destValue){
            getPath(lca, startValue, path,leftPath);
            for(int index = 0; index < leftPath.size(); index ++ ){
                leftPath[index] = 'U';
            }
            return leftPath;
        }else{
           getPath(lca, startValue,path, leftPath);
            path = "";

             getPath(lca, destValue, path,rightPath);
            
            for(int index = 0; index < leftPath.size(); index ++ ){
                leftPath[index] = 'U';
            }
            
            return leftPath + rightPath; 
        }
        
        
    }
};