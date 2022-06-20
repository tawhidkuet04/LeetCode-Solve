
class FreqStack {
    
private:
    unordered_map< int , vector<int> > mp;
    unordered_map<int, int> priorityMp;
    int maxElement =0;
public:
    
    FreqStack() {
        maxElement = 0;
    }
    
    void push(int val) {
        priorityMp[val] ++ ;
        if(priorityMp[val] > maxElement){
           maxElement= priorityMp[val];
        }
        mp[priorityMp[val]].push_back(val);
    }
    
    int pop() {
        auto vec = mp[maxElement];
        int topFreq = vec.back();
        mp[maxElement].pop_back();
        if(mp[maxElement].size() == 0){
             maxElement--;
        }
        priorityMp[topFreq] --;
       
        
        return topFreq;
        
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