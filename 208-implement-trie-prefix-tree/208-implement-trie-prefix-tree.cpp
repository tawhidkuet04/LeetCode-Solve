class Node{
    Node *links[26];
    bool flag = false;
    
    public:
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    
    Node* get(char c){
        return  links[c - 'a'];
    }
    
    void setKey(char c, Node *node){
        links[c - 'a'] = node;
    }
    
    void setEnd(){
        this->flag = true;
    }
    
    bool isEnd(){
        return this->flag;
    }
};

class Trie {
private: 
    Node *root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int index = 0; index < word.size(); index ++ ){
            if(!node->containsKey(word[index])){
                node->setKey(word[index], new Node());
                
            }
            node = node->get(word[index]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        
        for(int index = 0; index < word.size(); index ++ ){
            if(node->containsKey(word[index])){
                node = node->get(word[index]);
            }else{
                return false;
            }
        }
        
        return node->isEnd();
        
        
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(int index = 0; index < prefix.size(); index ++ ){
            if(node->containsKey(prefix[index])){
                node = node->get(prefix[index]);
            }else{
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */