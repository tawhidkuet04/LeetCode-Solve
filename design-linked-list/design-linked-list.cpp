

class MyLinkedList {
public:
    int size;
    ListNode *head = NULL;
    MyLinkedList() {
       size = 0;
    }
    
    int get(int index) {
        if(size == 0 || index >= size){
            return -1 ;
        }
        int count = 0 ;
        ListNode *temp = head;
        while(temp->next != NULL){
            if( count == index){
                break;
            }
            temp = temp->next;
            count ++;
           
        }
        return temp->val;
        
    }
    
    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        if(size == 0){
            head = newNode;
            head->next = NULL;
        }else{
            ListNode *temp = head;
            head = newNode; 
            newNode->next = temp;
        }
        size ++;
    }
    
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        if(size == 0){
            head = newNode;
            head->next = NULL;
        }else{
            ListNode *tempNode = head;
            while(tempNode->next != NULL){
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }
        size ++ ;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }
        int count = 1 ;
        ListNode *tempNode = head;
        ListNode *newNode = new ListNode(val);
        size++;
        if(index == 0){
            newNode->next = tempNode;
            head = newNode;
            return;
        }
        
        while(tempNode->next != NULL){
            if( count == index){
                newNode->next = tempNode->next;
                tempNode->next = newNode;
                return ;
            }
            tempNode = tempNode->next;
            count ++ ;
            
        }
        tempNode->next = newNode;
       
    }
    
    void deleteAtIndex(int index) {
        if(index >= size){
            return;
        }
        ListNode *tempNode = head;
        size--;
        if(index == 0){
            head = head->next;
            return;
        }
        int count = 1 ;
        
        while(tempNode->next != NULL){
            if( count == index){
                tempNode->next = tempNode->next->next;
                return ;
            }
            tempNode = tempNode->next;
            count ++ ;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */