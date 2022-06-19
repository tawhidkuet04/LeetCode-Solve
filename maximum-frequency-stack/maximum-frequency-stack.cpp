
class FreqStack {
    
private:
    map< int , vector<int> > mp;
    unordered_map<int, int> priorityMp;
    map< int , vector<int> > :: reverse_iterator it;
public:
    
    FreqStack() {
    }
    
    void push(int val) {
        priorityMp[val] ++ ;
        mp[priorityMp[val]].push_back(val);
    }
    
    int pop() {
        it = mp.rbegin();
        auto vec = it->second;
        int top = vec.back();
        it->second.pop_back();
        
        if(it->second.size() == 0){
            mp.erase(mp.find(it->first));
        }
        priorityMp[top] --;
        return top;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// 1 2 3 1 
    
//     5 7 5
        
//      5 -- 1
//      7 -- 1
      
        
        
//      1 --> 5, 7

     
        
        
        
    
   // 1 --- 1
   // 2 --- 2