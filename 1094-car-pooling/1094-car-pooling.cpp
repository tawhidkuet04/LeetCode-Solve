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
        
        if(path[0] >capacity) return false;
        
        for(int index = 1; index <= mx; index ++ ){
            path[index] += path[index - 1];
            if(path[index] > capacity) return false;
        }
        return true;
    }
};