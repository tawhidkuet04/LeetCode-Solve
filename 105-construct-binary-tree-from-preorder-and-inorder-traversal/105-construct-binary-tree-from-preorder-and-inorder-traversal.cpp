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
     unordered_map<int,int> mp ;
    
    TreeNode* constructTree(int *ind , int l , int r,vector<int>& inorder, vector<int>& preorder){
        
        if( l > r){
            return NULL;
        }
        
        TreeNode *newNode = new TreeNode(preorder[*ind]);
        int val = preorder[*ind] ;
        int in = mp[val];
        (*ind)++;
        newNode->left = constructTree( ind ,l , in-1,inorder,preorder);
        newNode->right = constructTree(  ind, in +1 , r ,inorder,preorder);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inLength = (int)inorder.size();
        if(inLength == 0 ) return NULL;
        for(int i = 0 ; i < inLength ; i ++ ){
            mp[inorder[i]] = i ;
        }
        int ind = 0 ;
        return constructTree( &ind,0,inLength-1,inorder,preorder);
    }
};