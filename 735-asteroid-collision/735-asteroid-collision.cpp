class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        int sz = asteroids.size();
        
        for(int index = 0; index < sz; index ++ ){
             st.push_back(asteroids[index]);
            
             while(st.size() >= 2){
                 int right = st.back();
                 st.pop_back();
                 int left = st.back();
                 st.pop_back();
                 
                 int collision = right * left;
                 
                 if(collision < 0){
                     if(left > 0 ){
                     if(abs(right) >  abs(left)){
                         st.push_back(right);
                     }else if(abs(right) <  abs(left)){
                             st.push_back(left);
                      }
                     }else{
                         st.insert(st.end(),{left,right});
                         break;
                     }
                    
                 }else{
                    st.insert(st.end(),{left,right});
                     break;
                 }
             }
        }
        

        return st;
    }
};
