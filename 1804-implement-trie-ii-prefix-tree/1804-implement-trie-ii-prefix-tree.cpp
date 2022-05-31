struct Node{
    Node *links[26];
    int count = 0;
    int endCount = 0 ;
    

    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    } 
    
    void setKey(char c, Node *node){
        links[c - 'a'] = node;
    }
    
    Node *get(char c){
        return links[c - 'a'];
    }
    
    void setCount(){
        count ++ ;
    }
    
    int getCount(){
        return count;
    }
    
    void setEndCount(){
         endCount++;
    }
    
    int getEndCount(){
        return endCount;
    }
    
    void decreseCount(){
        count -- ;
    }
    
    void decreaseEndCount(){
        endCount--;
    }
};


class Trie {
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
            node->setCount();
        }
        
        node->setEndCount();
    }
    
    int countWordsEqualTo(string word) {
        
         Node *node = root;
        
        for(int index = 0; index < word.size(); index ++ ){
            if(node->containsKey(word[index])){
                 node = node->get(word[index]);
            }else{
                return 0;
            }
        }
        
        return node->getEndCount();
        
    }
    
    int countWordsStartingWith(string prefix) {
        Node *node = root;
        
        for(int index = 0; index < prefix.size(); index ++ ){
            if(node->containsKey(prefix[index])){
                 node = node->get(prefix[index]);
            }else{
                return 0;
            }
        }
        
        return node->getCount();
    }
    
    void erase(string word) {
         Node *node = root;
        
        for(int index = 0; index < word.size(); index ++ ){
            if(node->containsKey(word[index])){
                 node = node->get(word[index]);
            }
            node->decreseCount();
        }
        
       node->decreaseEndCount();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */