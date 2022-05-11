/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, TreeNode* par, unordered_map<TreeNode*,TreeNode*> &parMp){
        if(root == NULL) return;
        
        parMp[root] = par;
        
        dfs(root->left, root, parMp);
        dfs(root->right, root, parMp);
        
    }
    
    void bfs(TreeNode *root, int k, unordered_map<TreeNode*,TreeNode*> mp, vector<int> &ans){
        unordered_map<TreeNode*,int> vis;
        
        queue<TreeNode *> q;
        
        q.push(root);
        vis[root] = 1;
        
        int distance = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            
            for(int index = 0; index < sz; index ++){
                auto top = q.front();
                q.pop();
                
                ans.push_back(top->val);
                
                if(top->left  && !vis[top->left]){
                    q.push(top->left);
                    vis[top->left] = 1;
                }
                if(top->right && !vis[top->right]){
                    q.push(top->right);
                    vis[top->right] = 1;
                }
                if(mp[top] && !vis[mp[top]] ){
                    q.push(mp[top]);
                    vis[mp[top]] = 1;
                }
            }
            if(distance == k){
                break;
            }else{
                ans.clear();
            }
            
            distance ++;
        }
        
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parMp;
        
        dfs(root, NULL, parMp);
        
        vector<int> ans;
        
        bfs(target, k, parMp, ans);
        
        return ans;
        
    }
};