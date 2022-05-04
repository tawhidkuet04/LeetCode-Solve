class MinStack {
public:
    
    stack<int> st;
    stack< pair<int, int > > minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(minSt.empty() || minSt.top().first > val ){
            minSt.push(make_pair(val, 1));
        }else if (minSt.top().first == val ){
             
             minSt.top().second ++;
        }
    }
    
    void pop() {
        if(minSt.top().first == st.top()){
            minSt.top().second -- ;
            if(minSt.top().second == 0){
                minSt.pop();
            }
        }
        
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */