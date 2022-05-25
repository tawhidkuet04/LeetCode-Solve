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
    
    struct State{
        TreeNode *node;
        int verticalIndex;
        
        State(TreeNode *node, int verticalIndex){
            this->node = node ;
            this->verticalIndex = verticalIndex;
        }
    };
    
    void traverse(TreeNode *root, int curIndex, int &minIndex, int &maxIndex, 
                 unordered_map<int, vector<int> > &mp){
  
        queue<State> q;
        
        q.push(State(root, 0));
        
        while(!q.empty()){
            int qSize = q.size();
            
            for(int index = 0; index < qSize; index ++ ){
                
                State cur = q.front();
                q.pop();
                
                mp[cur.verticalIndex].push_back(cur.node->val);
                
                if(cur.node->left != NULL){
                    q.push(State(cur.node->left, cur.verticalIndex - 1));
                    minIndex = min(minIndex, cur.verticalIndex - 1);
                }
                
                if(cur.node->right != NULL){
                    q.push(State(cur.node->right, cur.verticalIndex + 1));
                    maxIndex = max(maxIndex, cur.verticalIndex + 1);
                }
                
                
            }
            
        }
        
        
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        int minIndex = 0, maxIndex = 0;
        unordered_map<int, vector<int> > mp;
        vector< vector<int> > ans;
        if(root == NULL) return ans;
        
        traverse(root, 0, minIndex, maxIndex, mp);
        

        for(int index = minIndex; index <= maxIndex; index ++){
            ans.push_back(mp[index]);
        }
        
        return ans;
    }
};