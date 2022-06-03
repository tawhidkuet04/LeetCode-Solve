struct Node{
    Node *links[26];
    vector<string> strList;
    
    bool containsKey(char c){
        return links[c - 'a'];
    }
    
    Node *get(char c){
        return links[c - 'a'];
    }
    
    void setKey(char c, Node *node){
        links[c - 'a'] = node;
    }
    
    void insertProduct(string product){
        if(strList.size() == 3){
            strList.push_back(product);
            sort(strList.begin(), strList.end());
            strList.pop_back();
        }else{
            strList.push_back(product);
            sort(strList.begin(), strList.end());
        }
        
    }
    
    vector<string> getProducts(){
        return this->strList;
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
        
        for(int index = 0; index < word.size(); index ++ ){
            if(!node->containsKey(word[index])){
                node->setKey(word[index], new Node());
            }
            node = node->get(word[index]);
            node->insertProduct(word);
        }
    }
    
    vector<string> getProductList(string prefix){
        Node *node = root;
        
        vector<string> products;
        
        for(int index = 0; index < prefix.size(); index ++ ){
            if(node->containsKey(prefix[index])){
                node = node->get(prefix[index]);
            }else{
                return products;
            }
        }
        
        products = node->getProducts();
       
        return products;
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