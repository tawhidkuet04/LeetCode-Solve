class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       vector< int > path(1001, 0);
        
        int sz = trips.size();
        
        int mx = 0 ;
        
        for(int index = 0; index < sz; index ++ ){
            int from = trips[index][1];
            int to = trips[index][2];
            int passenger = trips[index][0];
            
            path[from] += passenger;
            
            path[to] -= passenger;
                
            mx = max(mx, to);
        }
        
        int total = 0;
        
        for(int index = 0; index <= mx; index ++ ){
            total += path[index];
            if(total > capacity) return false;
        }
        return true;
    }
};