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
    
    void solve(TreeNode *root, vector<vector<int>> &paths, vector<int> &path){
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->val);
            paths.push_back(path);
            return;
        }
        
        path.push_back(root->val);
        // cout << root->val << endl;
        
        if(root->left != NULL){
             solve(root->left, paths, path);
             path.pop_back();
        }
       
        
        
        if(root->right != NULL){
              solve(root->right, paths,path);
               path.pop_back();
        }
      
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int> > paths;
        vector<int> path;
        solve(root, paths, path);
        
        vector<string> ans;
        
        for( auto vec: paths){
            string strPath = "";
            
            for(auto num : vec){
                cout << num << " ";
                if(strPath.empty()){
                    strPath += to_string(num);
                }else{
                    strPath += "->" + to_string(num);
                }
            }
            
            ans.push_back(strPath);
        }
        
        return ans;
    }
};