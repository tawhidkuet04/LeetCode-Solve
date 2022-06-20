struct Node{
    Node *links[26];
    int endCount = 0;
    int count = 0;
    int length = 0;

    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    
    void setKey(char c, Node *newNode){
        links[c - 'a'] = newNode;
    }
    
    Node *get(char c){
        return links[c - 'a'];
    }
    
    void setEndCount(){
        endCount ++ ;
    }
    
    int getEndCount(){
        return endCount;
    }
    
     void setCount(){
        count ++ ;
    }
    
    int getCount(){
        return count;
    }
    
    void setLength(int len){
        length = len;
    }
    
    int getLength(){
        return length;
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
             node->setCount();
         }
         node->setEndCount();
        
         node->setLength(word.size());
     }
    
    void getWord(Node *node, int &length, int &count){
        if(node->getEndCount() == 1 && node->getCount() == 1){
            length += node->getLength();
            count ++;
            return ;
        }
   
        for(char ch = 'a'; ch <= 'z'; ch ++ ){
            if(node->containsKey(ch)){
                getWord(node->get(ch), length, count);
            }
        }
    }
    
    
    int getTotalWords(){
        Node *node = root;
        int length = 0, count = 0;
        getWord(node, length, count);
        cout << length << endl;
        return length + count;
    }
  
};


class Solution {
public:
    
    
    
    int minimumLengthEncoding(vector<string>& words) {
        Trie *trie = new Trie();
        unordered_map<string, int> mp;
        for(auto &word: words){
            if(mp[word]) continue;
            mp[word] ++;
            reverse(word.begin(), word.end());
            trie->insertWord(word);
        }
        
        return trie->getTotalWords();
    }
};

