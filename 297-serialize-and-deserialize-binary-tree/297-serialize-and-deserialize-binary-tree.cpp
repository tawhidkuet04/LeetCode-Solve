/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    void getSerialize(TreeNode *root, string &str){
        if(root == NULL) {
            str += "null,";
            return ;
        }
        
        str += to_string(root->val) + ",";
        getSerialize(root->left, str);
        getSerialize(root->right, str);
        
        
        
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedTree = "";
        
        getSerialize(root, serializedTree);
        
        // cout << serializedTree << endl;
        
        return serializedTree;
      
    }

    void getStringArraySeparateByDelimeter(string data, vector<string> &nodes){
        stringstream s(data);
        string str;
        while(getline(s, str, ',')){
            nodes.push_back(str);
        }
    }
    
    
    TreeNode* createTree( vector<string> &nodes, int &index){
        if( index >= nodes.size() || nodes[index] == "null") {
            index ++ ;
            return NULL;
        }
        
        TreeNode *node = new TreeNode(stoi(nodes[index++]));
        
        node->left = createTree(nodes, index);
        node->right = createTree(nodes, index);
        
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        
      getStringArraySeparateByDelimeter(data, nodes);
        
//     for(int index = 0; index < nodes.size(); index ++ ){
// cout << nodes[index] << endl; }
        
       int index = 0;
       return createTree(nodes, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// 123nn45nnnn