struct Node{
    public:
    int key;
    int data;
    Node *left;
    Node *right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


class DoublyList{
    
    public:
    Node *head, *tail;
    
    

    int getData(Node *cur){
        return cur->data;
    }
    
    DoublyList(){
        head = new Node(-1);
        tail = new Node(-1);
        head->right = tail;
        tail->left = head;
    }
    
    
    void insertAtHead(Node *data){
        
        Node *next = head->right;
        
        head->right = data;
        data->left = head;
        
        next->left = data;
        data->right = next;
    }
    
    
    void insert(Node *cur, int data, int key){
        Node *newNode =  new Node(data);
        newNode->key = key;
        Node *nextNode = cur->right;
        
        cur->right = newNode;
        newNode->left = cur;
        
        newNode->right = nextNode;
        nextNode->left = newNode;
        
    }
    
    void remove(Node *cur){
        Node *prev = cur->left;
        Node *next = cur->right;
        
        prev->right = next;
        next->left = prev;
    }
    
    
    void print(){
//         Node *temp = head->right;
        
//         while(temp->data != -1){
//             cout << temp->data << " ";
//             temp = temp->right;
//         }
//         cout << endl;
    }
    
};
    
    
class LRUCache {
public:
    int capacity;
    int curSize;
    
    DoublyList list;
    unordered_map<int, Node* > mp;
    
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        list = DoublyList();
        curSize = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node *node = mp[key];

        list.remove(node);
        list.insertAtHead(node);
        
       
        return list.getData(node);
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            list.remove(mp[key]);
            mp.erase(key);
            
            
            Node *newNode = new Node(value);
            newNode-> key = key;
            list.insertAtHead(newNode);
            mp[key] = newNode;
            
            
            list.print();
            return;
        }
        
        
        if(curSize  == capacity){
            mp.erase(list.tail->left->key);
            list.remove(list.tail->left);
            curSize --;
        }
          
        Node *data = new Node(value);
        data->key = key;
        list.insertAtHead(data);
        mp[key] = data;
        curSize ++;
        
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

  // 3 4 5 3 4 3 4 
    
    