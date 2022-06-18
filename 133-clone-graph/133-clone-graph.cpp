/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   
    unordered_map< Node*, Node* > mp;
    void dfs(Node *node){
         
         queue<Node *> q;
       
         q.push(node);
        
        mp[node] = new Node(node->val);
        
        while(!q.empty()){
                Node *frontNode = q.front();
                q.pop();
                
               for( auto nextNode : frontNode->neighbors){
                   if(mp[nextNode] == NULL){
                       mp[nextNode] = new Node(nextNode->val);
                       q.push(nextNode);
                   }
                   
                    mp[frontNode]->neighbors.push_back(mp[nextNode]);
               }
            }
        
          
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)return  NULL ;
        dfs(node);
        
        return mp[node];
    }
};
//      1,
// 1----2
//  2   