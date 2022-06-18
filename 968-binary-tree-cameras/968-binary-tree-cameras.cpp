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
    
    int solve(TreeNode *node, int &cam){
        if(node == NULL){
            return 1;
        }
        
        int left = solve(node->left, cam);
        int right = solve(node->right, cam);
        
        if( left == 0 || right == 0 ){
            cam ++;
            return 2;
        }else if ( (left + right) % 2 == 1  || (left + right) == 4){
            return 1;
        }else{
            return 0;
        }
        
    }
    //  0 1
    //  1 1
    //  2 1
    // 2 2
  
    
    int minCameraCover(TreeNode* root) {
        int ans = 0;
       if(solve(root, ans) == 0) ans ++;
        
        return ans;
    }
};
// take = 1 + solve(1)
    

// notTake = 1
// //  1
    
//     take = 1 + 0
// 2  3   
//      4
//     5  6
//    7 
     
     
     