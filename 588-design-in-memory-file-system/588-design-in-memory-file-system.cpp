struct Node{
    unordered_map<string, Node*> links;
    bool isFile = false;
    string content;
     
    bool containsKey(string key){
        return links[key];
    }
    
    void setKey(string key, Node *node){
        links[key] = node;
    }
    
    Node* get(string key){
        return links[key];
    }
    void setFile(){
        this->isFile = true;
    }
    
    bool isItFile(){
        return this->isFile;
    }
    
    void setContent(string content){
        if(content.size() == 0) return;
        if(this->content.size() == 0){
             this->content = content;
        }else{
             this->content = this->content + content;
        }
       
    }
     
    string getContent(){
        return this->content;
    }
};

class Trie{
    private: 
      Node *root;
    
    public:
    
      Trie(){
          root = new Node();
      }
    
      Node *createPath(string path){
          Node *node = root;
          string dir = "";
          
          
          for(int index = 0; index < path.size(); index ++ ){
              if(path[index] != '/'){
                  dir += path[index];
              }else{
                  if(!node->containsKey(dir)){
                      node->setKey(dir, new Node());
                  }
                  node = node->get(dir);
                  dir = "";
              }
              
          }
          if(dir != "" && !node->containsKey(dir)){
                      node->setKey(dir, new Node());
                  }
                  node = node->get(dir);
          return node;
      }
    
      void appendPath(string path){
          Node *node = this->createPath(path);
      }
    
    void appendFile(string path, string content){
          Node *node = this->createPath(path);
          node->setFile();
          node->setContent(content);
    }
    
    string readFile(string path){
          Node *node = root;
          
          string dir = "";
          
          
          for(int index = 0; index < path.size(); index ++ ){
              if(path[index] != '/'){
                  dir += path[index];
              }else{
                  if(node->containsKey(dir)){
                     node = node->get(dir);
                  }
                  dir = "";
              }
          }
            if(dir != "" && node->containsKey(dir)){
                      node = node->get(dir);
                  }
                
        
        
        
        return node->getContent();
    }
    
    vector<string> getListPath(string path){
        Node *node = root;
          
         string dir = "";
         vector<string> paths;
          for(int index = 0; index < path.size(); index ++ ){
              if(path[index] != '/'){
                  dir += path[index];
              }else{
                  if(node->containsKey(dir)){
                     node = node->get(dir);
                  }
                  
                 
                  dir = "";
              }
          }
        
        
        
        if(dir != "" && node->containsKey(dir)){
              node = node->get(dir);
         }
        
        if(node->isItFile()){
                       paths.push_back(dir);
                       return paths;
                  }
        
        for( auto &key: node->links){
            // cout << key.first << endl;
            if(key.first != ""){
                paths.push_back(key.first);
            }
            
        }
        sort(paths.begin(), paths.end());
        return paths;
          
    }
    
    
};




class FileSystem {
private:
    Trie *trie;
    
public:
    
    
    FileSystem() {
        trie = new Trie();
    }
    vector<string> ls(string path) {
        return trie->getListPath(path);
    }
    
    void mkdir(string path) {
        trie->appendPath(path);
    }
    
    void addContentToFile(string filePath, string content) {
        trie->appendFile(filePath, content);
    }
    
    string readContentFromFile(string filePath) {
        return trie->readFile(filePath);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */