class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        int sz = asteroids.size();
        
        for(int index = 0; index < sz; index ++ ){
             st.push(asteroids[index]);
            
             while(st.size() >= 2){
                 int firstTop = st.top();
                 st.pop();
                 int secondTop = st.top();
                 st.pop();
                 
                 int collision = firstTop * secondTop;
                 
                 // cout << firstTop << " " << secondTop << endl;
                 
                 if(collision < 0){
                     if(secondTop > 0 ){
                     if(abs(firstTop) >  abs(secondTop)){
                         st.push(firstTop);
                     }else if(abs(firstTop) <  abs(secondTop)){
                             st.push(secondTop);
                      }
                     }else{
                          st.push(secondTop);
                         st.push(firstTop);
                         break;
                     }
                    
                 }else{
                    
                     st.push(secondTop);
                     st.push(firstTop);
                     break;
                 }
             }
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
