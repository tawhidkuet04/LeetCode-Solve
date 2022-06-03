class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        int sz = asteroids.size();
        
        for(int index = 0; index < sz; index ++ ){
             st.push_back(asteroids[index]);
            
             while(st.size() >= 2){
                 int firstTop = st.back();
                 st.pop_back();
                 int secondTop = st.back();
                 st.pop_back();
                 
                 int collision = firstTop * secondTop;
                 
                 if(collision < 0){
                     if(secondTop > 0 ){
                     if(abs(firstTop) >  abs(secondTop)){
                         st.push_back(firstTop);
                     }else if(abs(firstTop) <  abs(secondTop)){
                             st.push_back(secondTop);
                      }
                     }else{
                         st.push_back(secondTop);
                         st.push_back(firstTop);
                         break;
                     }
                    
                 }else{
                    
                     st.push_back(secondTop);
                     st.push_back(firstTop);
                     break;
                 }
             }
        }
        

        return st;
    }
};
