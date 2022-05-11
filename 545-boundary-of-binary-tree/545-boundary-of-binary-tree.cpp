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
    
    bool isLeaf(TreeNode *node){
        if(node->left == NULL && node->right == NULL) return true;
        else return false;
    }
    bool isLeft(int flag){
        return ( flag == 1);
    }
    
    bool isRight(int flag){
        return (flag == 2);
    }
    
    bool isRoot(int flag){
        return (flag == 0);
    }
    
    
    int leftBoundaryFlag(TreeNode *node, int flag){
        if(isLeft(flag)  || isRoot(flag)){
            return 1;
        }else if(isRight(flag) && node->right == NULL){
            return 2;
        }else return 3;
    }
    
    int rightBoundaryFlag(TreeNode *node, int flag){
        if(isRight(flag) || isRoot(flag)){
            return 2;
        }else if(isLeft(flag) && node->left == NULL){
            return 1;
        }else return 3;
    }
    
    void preOrder(TreeNode *root, vector<int> & leftBoundary, vector<int> &rightBoundary, vector<int> &leaf, int flag){
    
        if(root == NULL) return ;
        else if(isRight(flag)){
            rightBoundary.push_back(root->val);
        }else if(isLeft(flag) || isRoot(flag)){
            leftBoundary.push_back(root->val);
        }else if(isLeaf(root)){
            leaf.push_back(root->val);
        }
          cout << root->val << " " << flag << endl;
        preOrder(root->left, leftBoundary, rightBoundary, leaf, leftBoundaryFlag(root, flag));
         preOrder(root->right, leftBoundary, rightBoundary, leaf, rightBoundaryFlag(root, flag));
        
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> leftBoundary, rightBoundary, leaf;
        
        preOrder(root, leftBoundary, rightBoundary, leaf, 0);
        
        leftBoundary.insert(leftBoundary.end(), leaf.begin(), leaf.end());
        reverse(rightBoundary.begin(), rightBoundary.end());
        leftBoundary.insert(leftBoundary.end(), rightBoundary.begin(), rightBoundary.end());
        
        return leftBoundary;
        
        
    }
};

