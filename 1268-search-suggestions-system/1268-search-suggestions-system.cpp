struct Node{
    Node *links[26];
    bool end = false;
    
    bool containsKey(char c){
        return links[c - 'a'];
    }
    
    Node *get(char c){
        return links[c - 'a'];
    }
    
    void setKey(char c, Node *node){
        links[c - 'a'] = node;
    }
    
    void setEnd(){
        this->end = true;
    }
    
    bool isEnd(){
        return this->end;
    }
    
    
};


class Trie{
    private: 
    
    Node *root;
    
    public:
    
    Trie(){
        root = new Node();
    }
    
    void insertWord(string word){
        Node *node = root;
        // cout << word << endl;
        
        for(int index = 0; index < word.size(); index ++ ){
            if(!node->containsKey(word[index])){
                node->setKey(word[index], new Node());
            }
            node = node->get(word[index]);
        }
        node->setEnd();
    }
    
    vector<string> getProductList(string prefix){
        Node *node = root;
        
        vector<string> products;
        
        string str = prefix;
        
        for(int index = 0; index < prefix.size(); index ++ ){
            if(node->containsKey(prefix[index])){
                node = node->get(prefix[index]);
            }else{
                return products;
            }
        }
        
        
        dfs(node, str, products);
        
        return products;
      
        
    
    }
    
    
    void dfs(Node *node, string str, vector<string> &products){
        if(products.size() == 3) return ;
        
        if(node->isEnd()){
            products.push_back(str);
        }
        
        for(int index = 0; index < 26; index ++){
            char ch = index + 'a';
            
            if(node->containsKey(ch)){
                dfs(node->get(ch), str + ch, products);
            }
            
        }
    }
    
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector< vector<string> > ans;
        
        Trie *trie = new Trie();
        
        for(int index = 0; index < products.size(); index ++ ){
            trie->insertWord(products[index]);
        }
        
        string prefix = "";
        
        for(int index = 0; index < searchWord.size(); index ++ ){
            prefix += searchWord[index];
            
            ans.push_back(trie->getProductList(prefix));
        }
        
        return ans;
        
        
    }
};