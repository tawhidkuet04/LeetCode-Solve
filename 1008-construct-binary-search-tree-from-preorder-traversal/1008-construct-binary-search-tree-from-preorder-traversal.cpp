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
    
    TreeNode* build(vector<int>& preorder,
                    int &index, int  upperBound){
        
        if(index >= preorder.size()) return NULL;
        if(preorder[index] > upperBound) return NULL;
        
        int val = preorder[index];
        TreeNode *node = new TreeNode(preorder[index++]);
        node->left = build(preorder, index, val );
        node->right = build(preorder, index ,upperBound);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
       return build(preorder, index, INT_MAX);
        
    }
};