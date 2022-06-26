struct Node{
  int key;
  int val;
  Node *left;
  Node *right;
    
   Node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
  Node(int key, int val , Node *left, Node *right){
      this->key = key;
      this->val = val;
      this->left = left;
      this->right = right;
  }    
};


class DoublyList{
  private:
    Node *head, *tail;
    int size;
    
  public:
    DoublyList(){
        head = new Node(-1);
        tail = new Node(-1);
        head->right = tail;
        tail->left = head;
        size = 0;
    }
    
    int getSize(){
        return size;
    }
    
    void insertAtHead(Node *node){
        Node *next = head->right;
        head->right = node;
        node->left = head;
        
        node->right = next;
        next->left = node;
        size ++ ;
    }
    
    
    void removeTailNode(){
        this->removeNode(tail->left);
    }
    
    int getTailNodeKey(){
        return tail->left->key;
    }
    
    void removeNode(Node *node){
          
         
         Node *prev = node->left;
         Node *next = node->right;
        
         prev->right = next;
         next->left = prev;
        
         size -- ;
         
     
    } 
};



class LRUCache {
private:
    int cacheCapacty;
    unordered_map<int, Node*> mp;
    DoublyList *list;
    
public:
    LRUCache(int capacity) {
        
        cacheCapacty = capacity;
        list = new DoublyList();
    }
    
    int get(int key) {
        if(mp[key] != NULL){
            updateNode(key);
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    
    
    void put(int key, int value) {
        if(list->getSize() < cacheCapacty){
                if(mp[key] != NULL){
                    updateNode(key); 
                    mp[key]->val = value;
                    return;
                }
        }else{
            if(mp[key] != NULL){
                updateNode(key);  
                mp[key]->val = value;
                return;
                
            }else{
                mp[list->getTailNodeKey()] = NULL;
                list->removeTailNode();

            }
  
        }
        
        insertNode(key, value);
    }
    void updateNode(int key){
         Node *node = mp[key];
         list->removeNode(node);   
         list->insertAtHead(mp[key]);
    }
    
    
    void insertNode(int key, int value){
        Node *newNode = new Node(key, value, NULL, NULL);
          list->insertAtHead(newNode);
          mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */