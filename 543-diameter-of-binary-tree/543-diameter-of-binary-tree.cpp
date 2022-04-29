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
    int findDiameter(TreeNode *root, int &maxDiameter){
        if(root == NULL) return 0;
        
        int left = findDiameter(root->left, maxDiameter);
        int right =  findDiameter(root->right, maxDiameter);
        
        maxDiameter = max(left + right, maxDiameter);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0 ;
        int maxValueFromBothSide = findDiameter(root, maxDiameter);
        //cout << maxValueFromBothSide <<endl;
        return maxDiameter;
    }
};